#include <stdio.h>
#include <stdlib.h>


int strend (char *ptr1, char *ptr2){
    char *beg2 = ptr2;
    while (*ptr1 != '\0'){
        ptr1++;
    }
    while (*ptr2 != '\0'){
        ptr2++;
    }
    while ((*ptr1 == *ptr2) && (ptr2 != beg2)){
        ptr1--;
        ptr2--;
    }
    if ((ptr2 == beg2) && (*ptr1 == *ptr2 )){
        return 1;
    } else {
        return 0;
    }
}

void strcat (char *p1, char *p2){
    //printf ("%p\n", p1);
    //printf ("%p\n", p2);
    //int j = 0;
    char *beg1 = p1;
    char *beg2 = p2;
    while (*p1 != '\0'){
        p1++;
    }
    while ((*p1++ = *p2++) != '\0'){
            //p1++;
            //p2++;
    }
    printf("%s\n", beg1);
    printf("%s\n", beg2);
}

int main()
{
    char str1[100] = "This is the first string";
    char *pstr1 = &str1[0];
    char *str2 = "This is the second string";

    strcat(pstr1, str2);

    char *str3 = "Third string for strend testing.?";
    char *str4 = ".?";

    int res = strend (str3, str4);
    printf("%d\n", res);

    return 0;
}
