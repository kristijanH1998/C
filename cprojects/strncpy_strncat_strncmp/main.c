#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int strncmp2 (char *s, char *t, int n){
    for ( ; (*s == *t) && (n > 0) ; s++, t++, n--){
        if (n == 1){
            return 0;
        }
    }
    return (*s - *t);
}

void strncat2 (char *s, char *t, int n){
    while (*s != '\0'){
        s++;
    }
    for (;n > 0; n--){
        *s++ = *t++;
    }
    *s = '\0';
}

char *strncpy2 (char *s, char *t, int n){

    char *beg = s;

    int i;
    for (i = 0; (i < n) && (*t != '\0'); i++){
        *s++ = *t++;
    }
    while (i++ < n){
        *s++ = '\0';
    }
    return beg;

}


int main()
{
    char str1[] = "First string.";
    char str2[] = "abc";
    char str3[50] = "123456";
    char str4[] = "5678";
    char str5[] = "atsss";
    char str6[] = "stsss";

    printf ("%s\n", strncpy2(str1, str2, 3));

    strncat2(str3, str4, 3);
    printf ("%s\n", str3);

    printf("%d\n", strncmp2(str5, str6, 3));


    return 0;
    getchar();
}
