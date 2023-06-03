#include <stdio.h>
#include <math.h>

int zbrajanje_i_mnozenje (unsigned int* a, int* b)
{
         
    if (*a < *b) 
    {
        printf ("Veci je drugi broj \n");
    }
    else 
    {
         printf ("Veci je prvi broj \n");
    }
         
    printf ("Zbroj ta dva broja je %u \n", *a + *b);
    printf ("Umnozak ta dva broja je %u \n", (*a) * (*b));
}

void broj_znamenki (unsigned int* c, int* d)
{
    unsigned int n = 1;
    while (1==1)        //ili "while (true)", include stdbool.h
    {
        if (*c < pow (10, n))
        {
            printf ("prvi broj ima %ul znamenki", n);
            break;
        }
        n = n + 1;
        
    }
    
    
    
    
    //if (*c < (10^(*g)))
   //{
      // printf ("Prvi uneseni broj ima %i znamenki", *g)
   //}
    
}





int main(int argc, char **argv)
{
    printf ("Unesite prvi broj ");

    unsigned long broj1 = 0;
    scanf ("%ul", &broj1);
    
    printf ("Unesite drugi broj ");
    int broj2 = 0;
    scanf ("%i", &broj2); 
    
    zbrajanje_i_mnozenje (&broj1, &broj2);
    broj_znamenki (&broj1, &broj2);
        
    system("PAUSE");



    return 0;










}
