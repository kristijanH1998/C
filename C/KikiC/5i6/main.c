#include <stdio.h>
#include <stdlib.h>

void ChangeNr (int *a)
{
    *a = *a + 1;
}
    

int main(int argc, char **argv)
{
    int number = 5;
    printf ("Broj je %i\n", number);
    ChangeNr (*number);
    printf ("Rezultat je %i\n", number);
    


    system("PAUSE");
    return 0;
}
