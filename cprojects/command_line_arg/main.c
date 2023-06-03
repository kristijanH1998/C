#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];
int reverse = 0;
int foldul = 0;
int directory = 0;

enum {NO, YES};

int strcmp2 (char *s, char *t){
    if (directory == YES){
        while(!isdigit(*s) && !isalpha(*s) && !isspace(*s)){
            s++;
        }
		while(!isdigit(*t) && !isalpha(*t) && !isspace(*t)){
            t++;
		}
    }
    for ( ; foldul ? (tolower(*s) == tolower(*t)) : (*s == *t); s++, t++){
        if (directory == YES){
            while(!isdigit(*s) && !isalpha(*s) && !isspace(*s)){
                s++;
            }
            while(!isdigit(*t) && !isalpha(*t) && !isspace(*t)){
                t++;
            }
        }
        if (*s == '\0'){
            return 0;
        }
    }

    if (foldul == YES){
        return (tolower(*s) - tolower(*t));
    } else {
        return (*s - *t);
    }
}

int getline (char s[], int lim ){
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if (c == '\n'){
        s[i++] = c;
    }
    if (c == '\n' && s[0] == '~'){
        return 0;
    }

    s[i] = '\0';
    return i;
}

char *alloc (int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

int readlines (char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = alloc(len)) == NULL){
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}

void swap (void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp (char *s1, char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2){
        return -1;
    }
    else if (v1 > v2) {
        return 1;
    }
    else {
        return 0;
    }
}

void qsort2 (void *v[], int left, int right, int (*comp)(void*, void*)){
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right){
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++){
        if (reverse == YES){
            if ((*comp)(v[i], v[left]) > 0){
                swap(v, ++last, i);
            }
        } else {
            if ((*comp)(v[i], v[left]) < 0){
                swap(v, ++last, i);
            }
        }
    }
    swap(v, left, last);
    qsort2(v, left, last - 1, comp);
    qsort2(v, last + 1, right, comp);
}

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && ((strcmp2(argv[1], "-rn")) == 0 || strcmp2(argv[1], "-nr") == 0)){
        numeric = YES;
        reverse = YES;
    } else if (strcmp2(argv[1], "-r") == 0){
        reverse = YES;
    } else if (strcmp2(argv[1], "-n") == 0){
        numeric = YES;
    } else if (strcmp2(argv[1], "-f") == 0){
        foldul = YES;
    } else if (strcmp2(argv[1], "-d") == 0){
        directory = YES;
    } else if (strcmp2(argv[1], "-df") == 0 || strcmp2(argv[1], "-fd") == 0){
        directory = YES;
        foldul = YES;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort2((void **) lineptr, 0, nlines - 1,
            (int (*)(void*, void*))(numeric ? numcmp : strcmp2));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
