#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define BUFSIZE 100
#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))
#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatite", 0,
    "while", 0
};

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp>0) ? buf[--bufp] :getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
        else buf[bufp++] = c;
}

int binsearch(char *word, struct key keytab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low+high) /2;
        if ((cond = strcmp(word, keytab[mid].word)) < 0){
            high = mid - 1;
        } else if (cond > 0){
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int getword (char *word, int lim){
    int c;
    int getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch())){
        ;
    }
    if (c != EOF){
        *w++ = c;
    }
    if (c == '/'){        //comment
        if ((c = getch()) == '/'){
            *w++ = c;
            while ((c = getch()) != '\n'){
                *w++ = c;
            }
            *w = '\0';
            return word[0];
        } else if (c == '*'){
            *w++ = c;
            LABEL1:
            while ((c = getch()) != '*' && (c != EOF)){
                *w++ = c;
            }
            if (c == EOF){
                ungetch(c);
            } else {
                *w++ = c;
                if ((c = getch()) == '/'){
                    *w++ = c;
                } else {
                    *w++ = c;
                    goto LABEL1;
                }
            }
            *w = '\0';
            return word[0];
        } else {
            ungetch(c);
            return word[0];
        }
    } else if (c == '#'){   //preprocessor lines
        while ((c = getch()) != '\n'){
            *w++ = c;
        }
        return word[0];
    } else if (c == '_'){   //underscores
        while (isalnum(c = getch())){
            ;
        }
        ungetch(c);
        return word[0];
    } else if (c == '\"'){   //string constant
        while ((c = getch()) != '\"' && (c != EOF)){
            *w++ = c;
        }
        if (c == EOF){
            ungetch(c);
        }
        return word[0];
    }
    if (!isalpha(c)){
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++){
        if (!isalnum(*w = getch())){
            if (*w != '_'){
                ungetch(*w);
                break;
            } else {
                return(*w);
            }
        }
    }
    *w = '\0';
    return word[0];
}

int main()
{
    printf("%c\n",*((*(keytab + 5)).word + 2));
    //printf("%s\n", keytab[7].word);
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF){
        if (isalpha(word[0])){
            if ((n = binsearch(word, keytab, NKEYS)) >= 0){
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++){
        if (keytab[n].count > 0){
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}
