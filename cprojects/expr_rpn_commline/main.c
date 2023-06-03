#include <stdio.h>
#include <stdlib.h>
#define MAX 100



int main(int argc, char **argv)
{
    //int stack[MAX];
    int *top = (int*)malloc((argc - 1) * sizeof(int));
    //int *top = stack;


    //printf("%c\n", *argv[1]);
    //printf("%p\n", argv);
    //printf("%p\n", argv[0]);
    //printf("%p\n", *argv);
    //printf("%p\n", argv[1]);
    //printf("%p\n", *++argv);

    //printf("%p\n", &argv);
    //printf("%p\n", &argv[0]);

    for (int i = 1; i < argc; i++){
        if(isdigit(**(argv + i))){
            *top++ = atoi(*(argv + i));
            //printf("%c\n", **(argv+i));
            //printf("%d\n", stack[i-1]);
        } else if (**(argv + i) == '+'){
            int a = *(--top);
            int b = *(--top);
            *top++ = a + b;
        } else if (**(argv + i) == '*'){
            int a = *(--top);
            int b = *(--top);
            *top++ = a * b;
        } else if (**(argv + i) == '-'){
            int a = *(--top);
            int b = *(--top);
            *top++ = b - a;
        } else if (**(argv + i) == '/'){
            int a = *(--top);
            int b = *(--top);
            *top++ = b / a;
        } else if (**(argv + i) == '%'){
            int a = *(--top);
            int b = *(--top);
            *top++ = b % a;
        }

    }

    printf("%d\n", *(--top));
    free(top);

    return 0;
}
