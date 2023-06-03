#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char buf[100];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {

    if (bufp >= 100)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getfloat (float *pn){
    int c, sign;

    while (isspace(c = getchar())){
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch (c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-'){
        char ch = c;
        c = getchar();
        if (!isdigit(c)){
            ungetch(ch);
            ungetch(c);
            return;
        }
    }
    for (*pn = 0; isdigit(c); c = getchar()){

        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.'){
        float n = 10.0;
        c = getchar();
        while (isdigit(c)){
            *pn = *pn + ((float)(c - '0') / n);
            n = n * 10.0;
            c = getchar();
        }
    }
    *pn *= sign;
    if (c != EOF){
        ungetch (c);
    }
    printf("%f\n", *pn);
    return c;

}

int getint (int *pn){

    int c, sign;

    while (isspace(c = getchar())){
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch (c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-'){
        char ch = c;
        c = getchar();
        if (!isdigit(c)){
            ungetch(ch);
            ungetch(c);
            return;
        }
    }
    for (*pn = 0; isdigit(c); c = getchar()){

        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF){
        ungetch (c);
    }
    printf("%d\n", *pn);
    return c;
}

int main()
{
    int a = 0;
    int *b = &a;
    float c = 0.0;
    float *d = &c;

    getint (b);
    printf ("%c\n", buf[0]);
    printf ("%c\n", buf[1]);

    getfloat(d);

    float df = 23.232;
    printf ("%f\n", (float) df/10);

    return 0;
    getchar();
}
