#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c = 0;

void printlines (char **input, int line, int n){

    //printf("%s\n", *input);
    //printf("%s\n", *(input + 1));
    //printf("%s\n", *(input + 2));

    n = n - '0';
    while ((n--) > 0){
        printf("%s\n", *(input + (line - n)));
    }

    //printf("%d\n", line);
    //printf("%c\n", n);
}

int getline (char *fillstr){
    int i = 2;
    int j = 0;
    int strsize = 0;
    while ((c = getchar()) != '\n'){
        if (c == '~'){
            break;
        }
        fillstr = (char *) realloc (fillstr, (++i) * sizeof(char));
        *(fillstr + (j++)) = c;
        strsize++;
    }
    *(fillstr + j) = '\0';
    return strsize;
}


int main(int argc, char *argv[])
{
    char *fillstr = (char *) malloc (sizeof(char) * 2);

    int line = 0;
    int inpsize = 1;
    int strsize = 0;
    char **input = (char **) malloc (sizeof(char *) * inpsize);

    while (c != '~') {
        strsize = getline(fillstr);
        if (strsize == 0){
            break;
        }
        *(input + line) = (char *) malloc ((strsize + 1) * sizeof(char));
        input = (char**) realloc (input, (++inpsize) * sizeof(char *));
        strcpy(*(input + (line++)), fillstr);

        //*(input + (line++)) = fillstr;
    }
    *(input + line) = NULL;

    //printf("%s\n", fillstr);

    //printf("%c\n", *(*(argv + 1) + 1));
    printlines(input, line - 1, *(*(argv + 1) + 1));

    getchar();
    return 0;
}
