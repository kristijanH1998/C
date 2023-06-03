#include <stdio.h>
#include <stdlib.h>
#define DOSTH(y) ++y
#define PI 3.14
#define DOCALC(x,a) (((x+2) * a)) * PI
#define TOTEXT(s) #s

#define PRINT(i, limit) while (i < limit) \
                        { \
                            printf("GeeksQuiz "); \
                            i++; \
                        }\
                        printf("\n");
#define PRINTMULT(i) for ( ; i > 0; i--){\
                            printf("One ");\
                        }\
                        printf("\n");


void deallocate (int **ptr){
    //printf("%d\n", *(*ptr + 3));

    if (*ptr){
        free(*ptr);
        *ptr = NULL;
    }
    //if (*ptr){
    //    printf("%d\n", *(*ptr + 3));
    //}
}

int main()
{
    char *ptr = "GeeksQuiz";
    int x = 10;
    double c = 21;
    double d = 22.21;
    int a = 10000;
    float f = 23.112;
    printf("%s  ", DOSTH(ptr));
    printf("%d ", DOSTH(x));
    printf("%f ", DOSTH(c));

    printf("%llu %llu %llu %llu %llu %llu\n", sizeof(ptr), sizeof(x), sizeof(c), sizeof(d)
           , sizeof(a), sizeof(f));
    printf("%f\n", DOCALC(7,4));
    printf("%s\n", TOTEXT(This is some text.));
    int i = 0;
    int j = 5;
    PRINT(i, 4);
    PRINTMULT(j);

    int *p = (int*) malloc(sizeof(int) * 10);
    *(p + 3) = 17;
    printf("%d\n", *(p + 3));
    deallocate(&p);
    char **p2 = (char**) malloc(sizeof(char*) * 5);
    //*(*p2 + 2) = 'h';
    //printf("%c\n", *(*p2 + 2));
    //deallocate(&p2);

    return 0;
}
