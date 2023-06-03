#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100


struct tnode {
    int wordlist_size;
    struct tnode *left;
    struct tnode *right;
    char **wordlist;
};

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

char **aralloc(int wordlist_size, char** wordlist){
    if (wordlist_size == 0){
        return (char**) malloc (sizeof(char*));
    } else {
        return (char**) realloc (wordlist, sizeof(char*) * (wordlist_size + 1));
    }
}

struct tnode *addtree(struct tnode *p, char *w, int numofch_cmp)
{
    int cond;

    if (p == NULL) { /* new word (place into new tnode)*/
        p = talloc();
        p->wordlist_size = 0;
        p->wordlist = aralloc(p->wordlist_size, p->wordlist);
        p->wordlist_size++;
        *p->wordlist = mstrdup(w);
        p->left = p->right = NULL;
    }
    else if((cond = strncmp(w, *p->wordlist, 6)) == 0){  //add word to tnode's wordlist
        p->wordlist = aralloc(p->wordlist_size, p->wordlist);
        *((p->wordlist) + (p->wordlist_size)) = mstrdup(w);
        p->wordlist_size++;
    }
    else if(cond < 0){
        p->left = addtree(p->left, w, numofch_cmp);
    }
    else {
        p->right = addtree(p->right, w, numofch_cmp);
    }
    return p;
}


void treeprint(const struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        for (int i = 0; i < (p->wordlist_size); i++){
            (i == p->wordlist_size - 1) ? printf("%s", *(p->wordlist + i)) :
                printf("%s, ", *(p->wordlist + i));
        }
        printf("\n");
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

int main(int argc, char **argv){
    struct tnode *root;
    char word[MAXWORD];

    //char *ar[6];
    //printf("%d\n", sizeof(ar));
    //int a = sizeof(ar) / sizeof(char*);
    //printf("%d\n", a);

    //struct tnode *node1ptr = (struct tnode *) malloc (sizeof(struct tnode));
    //printf ("%d\n", sizeof(*node1ptr));

    printf("%d\n", **(argv + 1) - '0');
    root = NULL;
    while (getword(word, MAXWORD) != EOF){
        if (isalpha(word[0])){
            root = addtree(root, word, **(argv + 1) - '0');
        }
    }
    treeprint(root);
    return 0;
}
