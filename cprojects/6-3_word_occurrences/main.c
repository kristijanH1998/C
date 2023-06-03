#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100

int line = 1;
int preline = 1;

struct word {
    char *text;
    int *ln_occurr;
    int index;
    struct word *left;
    struct word *right;
};

char *mstrdup(char *s)
{
    char *p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

struct word *talloc(void)
{
    return (struct word *) malloc (sizeof(struct word));
}

int *ln_occurr_alloc(struct word *p){
    if(p->index == 0){
        return (int *) malloc (sizeof(int));
    } else {
        return (int *) realloc (p->ln_occurr, sizeof(int) * (p->index + 1));
    }
}

struct word *addtree(struct word *p, char *w)
{
    int cond;
    if (p == NULL) { /* new word */
        p = talloc();
        p->text = mstrdup(w);
        p->index = 0;
        p->ln_occurr = ln_occurr_alloc(p);
        *(p->ln_occurr + (p->index)) = line;
        p->index++;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->text)) == 0){
        if (*(p->ln_occurr + (p->index) - 1) != line){
            p->ln_occurr = ln_occurr_alloc(p);
            *(p->ln_occurr + (p->index)) = line;
            p->index++;
        }
    }
    else if(cond < 0)
        p->left = addtree(p->left, w);
    else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(const struct word *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%s ", p->text);
        int i = 0;
        while(i < p->index){
            (i == (p->index - 1)) ? (printf("%d", *(p->ln_occurr + (i++))))
                : (printf("%d, ", *(p->ln_occurr + (i++))));
        }
        printf("\n");
        treeprint(p->right);
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    int ch;
    //return (bufp > 0) ? buf[--bufp] : getchar();
    if (bufp > 0){
        ch = buf[--bufp];
    } else {
        ch = getchar();
        if (ch == 10){
            preline++;
        }
    }
    return ch;
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else {
        buf[bufp++] = c;
    }
}

int getword (char *word, int lim){
    int c;
    int getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()) && (c != '\n')){
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
    //int num = 45;
    //struct word word1 = {"automobile", &num};
    //printf("%s %d\n", word1.text, *word1.ln_occurr);

    //word_arr = (struct word*) malloc(sizeof(struct word));
    //(*word_arr).text = "firstword";
    //printf("%s\n",(*word_arr).text);

    //(*word_arr).ln_occurr = (int*) malloc(sizeof(int));
    //*((*word_arr).ln_occurr) = 32;
    //printf("%d\n", *((*word_arr).ln_occurr));
    //(*word_arr).ln_occurr = realloc ((*word_arr).ln_occurr, sizeof(int) * 2);
    //*((*word_arr).ln_occurr + 1) = 11;
    //for (int b = 0; b < 2; b++){
    //    printf("%d\n", *((*word_arr).ln_occurr + b));
    //}

    struct word *root;
    char word_inp[MAXWORD];

    root = NULL;
    while (getword(word_inp, MAXWORD) != EOF){
        if (isalpha(word_inp[0])){
            root = addtree(root, word_inp);
        }
        line = preline;
    }
    treeprint(root);
    return 0;
}
