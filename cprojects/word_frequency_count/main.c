#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100


struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int mystrcmp (char *s, char *t){
    for ( ; *s == *t; s++, t++){
        if (*s == '\0'){
            return 0;
        }
    }
    return *s - *t;
}

char *mstrdup(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc (sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) { /* new word */
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = mystrcmp(w, p->word)) == 0)
        p->count++;
    else if(cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}


void treeprint(const struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
    return;
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

int main(int argc, char *argv[]){
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF){
        if (isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}
