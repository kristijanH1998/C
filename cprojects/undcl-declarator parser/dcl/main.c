#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE  100
#define MAXTOKEN 100

enum {NAME,PARENS,BRACKETS,ARGUMENTS};
enum { NO, YES };

void errmsg(char *);

int tokentype;          /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type=char, int etc */
char out[1000];         /* output string */
int prevtoken = NO;
char token2[MAXTOKEN];
char string1[MAXTOKEN];
char buf[BUFSIZE];          /* buffer for ungetch */
char qualifier[MAXTOKEN];
int bufp = 0;               /* next free position in buf */
char *pstr1 = string1;

void errmsg(char *msg){
    printf("%s",msg);
    prevtoken = YES;
}

int check (void){
    int c, word = 0;
    char *pt = string1;
    c = getch();
    while (c != '('){
        *pt++ = c;
        if (isalpha(c)){
            word++;
            while (isalpha(c = getch())){
                *pt++ = c;
            }
        } else {
            c = getch();
        }
    }
    while (c != '\n'){
        *pt++ = c;
        c = getch();
    }
    *pt++ = c;
    *pt = '\0';
    return word;
}

int tokenizer (void){
    int c;
    char *pt = token2;
    while((c = *pstr1++) == ' ' || c == '\t'){
        ;
    }

    while(c != ',' && c != ')'){
        *pt++ = c;
        c = *pstr1++;
        if (c == ' '){
            *pt++ = c;
            while (*pstr1 == ' '){
                pstr1++;
            }
            c = *pstr1++;
        }
    }
    if (c == ','){
        if (*(pt - 1) == ' ' ){
            *--pt = c;
        }
        *pt++ = c;
        *pt++ = ' ';
    }

    *pt = '\0';
    strcat(token, token2);
    if (c == ')'){
        return 1;
    } else {
        return 0;
    }
}

int gettoken(void) {
    int c, done = 0;
    char *p = token;

    if(prevtoken == YES)
    {
        prevtoken = NO;

        return tokentype;
    }

    while((c = *pstr1++) == ' ' || c == '\t'){
        ;
    }

    if(c == '('){
        if((c = *pstr1++) == ')') {
            strcpy(token,"()");
            return tokentype = PARENS;
        } else if (c != '*'){
            pstr1--;
            *p = '\0';
            while (done != 1){
                done = tokenizer();
            }
            return tokentype = ARGUMENTS;
        } else {
            pstr1--;
            return tokentype = '(';
        }
    } else if ( c == '['){
            for(*p++ = c; (*p++ = *pstr1++) != ']';){
                ;
            }
            *p = '\0';
            return tokentype = BRACKETS;
    } else if (isalpha(c)){
        for(*p++ =c; isalnum(c = *pstr1++);){
            *p++ = c;
        }
        *p = '\0';
        pstr1--;
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}

int getch(void)             /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp]:getchar();
}

void ungetch(int c)     /* push a character back on input */
{
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters \n");
    } else{
        buf[bufp++] = c;
    }
}

void dcl(void)
{
    int ns;

    for(ns=0;gettoken()=='*';){ /* count *'s */
        ns++;
    }

    dirdcl();
    while(ns-- > 0){
        strcat(out,"pointer to ");
    }
}

void dirdcl(void)
{
    int type;

    if (tokentype == '(')    /* dcl */
    {
        dcl();

        if (tokentype != ')'){
            errmsg("error: missing ) \n");
        }
    } else if (tokentype == NAME){  /* variable name */
        strcpy(name,token);
    } else {
        errmsg("error: expected name or (dcl) \n");
    }

    while((type = gettoken()) == PARENS || type == BRACKETS || type == ARGUMENTS){
        if(type == PARENS){
            strcat(out,"function returning ");
        }
        else if (type == BRACKETS){
            strcat(out,"array");
            strcat(out,token);
            strcat(out," of ");
        } else {
            strcat(out, "function receiving ");
            strcat(out, token);
            strcat(out, " and returning ");
        }
    }
}

int main(void) {
    int words;
    if ((words = check()) == 3){
            gettoken();
            strcpy(qualifier, token);
    } else {
        qualifier[0] = '\0';
    }
    if(gettoken()!=EOF){

        strcpy(datatype,token);

        out[0]='\0';
        dcl();

        if(tokentype != '\n'){
            printf("syntax error \n");
        }

        printf("%s: %s%s %s \n",name,out,qualifier,datatype);
    }
    return 0;
}
