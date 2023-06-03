#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c, tabstop, pos = 0;
    int mn = 0;
    int clmn = 0;

    if (argc > 1){
        if ((argc == 3) && (**(argv + 1) == '-') && (**(argv + 2) == '+')){
            mn = 1;
            tabstop = (*(*(argv + 2) + 1)) - '0';
        } else {
            tabstop = atoi(*(++argv));
        }
    } else {
        tabstop = 8;
    }
    while ((c = getchar()) != EOF){
        clmn++;
        if ((mn != 0) && clmn < ((*(*(argv + 1) + 1)) - '0')){
            putchar(c);
            pos++;
            if (c == '\t'){
                pos = 0;
            }
            if (c == '\n'){
                clmn = 0;
            }
            continue;
        }
        if (c == '\t'){
            for (int i = 0; i < (tabstop - (pos % tabstop)); i++){
                putchar('#');
            }
            pos = 0;
        } else if (c == '\n'){
            putchar(c);
            pos = 0;
            clmn = 0;
            if (argc > 1 && (*(argv + 1)) != NULL && (mn == 0)){
                tabstop = atoi(*(++argv));
            }
        } else {
            putchar(c);
            pos++;
        }
    }
    return 0;
}
