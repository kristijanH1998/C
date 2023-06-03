#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int mn = 0;
int clmn = 0;

int main(int argc, char *argv[])
{
    int c, tabstop, chnum = 0;
    int blnum = 0;
    int blnumseg = 0; // number of blanks before a char that is not a blank

    printf("%c\n", *(*(argv + 1) + 1));
    printf("%d\n", argc);
    printf("%c\n", **(argv + 2));
    //printf("%p\n", *(argv + 1) + 1);
    //printf("%p\n", *(argv + 1));
    //printf("%d\n", ((*(*(argv + 1) + 1)) - '0'));

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
            if (c == '\n'){
                clmn = 0;
            }
            continue;
        }
        if (c == ' '){
            while (c == ' '){
                blnum++;
                blnumseg++;
                if ((chnum + blnum) == tabstop){
                    if (tabstop == 8){
                        putchar('\t');
                    } else {
                        for (int g = 1; g <= blnumseg; g++){
                            putchar(' ');
                        }
                    }
                    //putchar('\t');
                    goto LABEL;
                }
                c = getchar();
                clmn++;
                if ((mn != 0) && clmn < ((*(*(argv + 1) + 1)) - '0')){
                    putchar(c);
                    continue;
                }
                if (c != ' '){
                    for ( int i = blnumseg; i > 0; i--){
                        putchar('#');
                    }
                    goto LABEL2;
                }
            }
        }
        LABEL2:
        if (c == '\n' || c == '\t'){
            putchar(c);
            goto LABEL;
        } else {
            putchar(c);
            chnum++;
            blnumseg = 0;
        }
        if ((blnum + chnum) == tabstop){
            LABEL:
            blnum = 0;
            chnum = 0;
            blnumseg = 0;
            clmn = 0;
            if (argc > 1 && (*(argv + 1)) != NULL && (mn == 0)){
                tabstop = atoi(*(++argv));
            }
        }
    }
    return 0;
}
