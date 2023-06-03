#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(t, x, y) {\
    t temp;\
    temp = x;\
    x = y;\
    y = temp;\
    }
#define typeprint(f, i){\
    printf("f = %d \t i = %d \n", f, i);\
    }

void itoa2 (int n, char s[]);
void reverse (char s[], int j);

int main(void)
{
    char s[100];
    int n = -445;

    itoa2 (n, s);

    printf("%s\n", s);

    int a, b;
    double c, d;
    a = 4;
    b = 62;
    c = 34.22;
    d = 83.21;
    printf ("a = %d \t b = %d \n", a, b);
    swap (int, a, b);
    printf ("a = %d \t b = %d\n", a, b);
    printf ("c = %lf \t d = %lf \n", c, d);
    swap (double, c, d);
    printf ("c = %lf \t d = %lf \n", c, d);
    int f, i;
    f = 6;
    i = 31;
    typeprint (f, i);





    return 0;
    getchar();
}

void itoa2 (int n, char s[]){
    static int sign, solved;
    static int i = 0;

    if (n < 0){
        sign = n;
        n = -n;
    }

    if ((n / 10) > 0){
        s[i++] = n % 10 + '0';
        n /= 10;
        itoa2(n, s);
        if (solved == 1){
            return;
        }
    } else {
        s[i++] = n + '0';
    }
    solved = 1;

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse (s, strlen(s)-1);
}

void reverse (char s[], int j){
    static int i = 0;
    static int c;

    while(i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
        reverse(s, j);
    }
}
