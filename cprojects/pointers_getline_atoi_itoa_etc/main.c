#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define NUMBER '0'

char buf [BUFSIZE];
int bufp = 0;

int getch (void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch (int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getop (char *s){
    int c;
    char *beg = s;

    while ((*s = c = getch()) == ' ' || c == '\t'){
        ;
    }
    s++;
    *s = '\0';
    if (!isdigit(c) && c != '.'){
        return c;
    }

    if (isdigit(c)){
        while (isdigit(*s++ = c = getch())){
            ;
        }
    }
    if (c == '.'){
        while (isdigit(*s++ = c = getch())){
            ;
        }
    }
    *s = '\0';
    if (c != EOF){
        ungetch(c);
    }
    printf("%s\n", beg);
    return NUMBER;

}

int strindex2 (char *s, char *t){

    for (int i = 0; *s != '\0'; s++, i++){
        char *temp = s;
        for (;(*t != '\0') && (*s == *t); s++, t++){
            ;
        }
        if ((temp != s) && (*t == '\0')){
            return i;
        }
    }
    return -1;
}

void itoa2 (int n, char *s){
    int sign;
    char *beg = s;
    if ((sign = n) < 0){
        n = -n;
    }
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0){
        *s++ = '-';
    }
    *s = '\0';
    reverse2(beg);
}

int strlen2 (char *s){
    int i = 0;
    while (*s++ != '\0'){
        i++;
    }
    return i;
}

void reverse2 (char *s){
    char c;
    int i = 0;
    char *fir = s;
    while ((*s != '\0') && (*(s+1) != '\0')){
        s++;
        i++;
    }
    //printf("%c\n", *fir);
    for (int j = 0; j <= (i / 2); fir++, s--, j++){
        c = *fir;
        *fir = *s;
        *s = c;
    }
}

int atoi2 (char *s){
    int n, sign;
    for (; isspace(*s); s++){
        ;
    }
    sign = (*s == '-') ? -1 : 1;
    if ((*s == '+') || (*s== '-')){
        s++;
    }
    for (n = 0; isdigit(*s); s++){
        n = 10 * n + (*s - '0');
    }
    return sign * n;

}

int getline (char *s, int lim){
    int c, i;

    i = 0;
    while ((--lim > 0) && (c = getchar()) != EOF && (c != '\n')){
        *s++ = c;
        i++;
    }
    if (c == '\n'){
        *s++ = c;
        i++;
    }
    *s = '\0';
    return i;
}

int main()
{
    char str1[] = "";
    char str2[] = "233";
    char str3[] = "reverse";
    char str4[] = "";

    char str5[] = "This is the test for strindex.";
    char str6[] = "h";
    char str7[] = "";

    printf("%d\n", getline (str1, 50));
    printf("%s\n", str1);

    printf("%d\n", atoi2(str2));
    reverse2(str3);
    printf("%s\n", str3);

    itoa2(944, str4);
    printf("%s\n", str4);

    printf("%d\n", strindex2(str5, str6));

    getop(str7);

    return 0;
}
