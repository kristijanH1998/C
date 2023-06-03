#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXTOKEN 100

enum { NAME,PARENS,BRACKETS };
int tokentype;   /* type of last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN]; /* identifier name */
char out[1000];
char datatype[MAXTOKEN];

int gettoken(void)
{
    int c,getch(void);
    void ungetch(int);

    char *p = token;

    while((c=getch()) == ' ' || c == '\t')
        ;

    if(c == '(')
    {
        if((c = getch()) == ')')
        {
            strcpy(token,"()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for(*p++ = c; ( *p++ = getch()) != ']';)
            ;
        *p ='\0';

        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for(*p++ = c; isalnum(c=getch()); )
            *p++ = c;

        *p = '\0';

        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch   */
int bufp = 0;           /* next free position in buf    */

int getch(void)         /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if ( bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}



int main()
{
    int type, next = 0;
    char temp[100];

    while (gettoken() != EOF){
        strcpy(out, token);
        while ((type = gettoken()) != '\n'){
            LABEL:
            if (type == PARENS || type == BRACKETS){
                strcat(out, token);
            } else if (type == '*'){
                if ((next = gettoken()) == NAME || next == '*'){
                    sprintf(temp, "*%s", out);
                    strcpy(out, temp);
                    if (next == NAME){
                        type = NAME;
                    } else {
                        type = '*';
                    }
                    goto LABEL;
                } else {
                    sprintf(temp, "(*%s)", out);
                    strcpy(out, temp);
                    type = next;
                    goto LABEL;
                }
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}
