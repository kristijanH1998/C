#include <stdio.h>
#include <stdlib.h>

void ispisi (int *broj)
{
   printf ("Imate %i godina \n", *broj); 
}


int main(int argc, char **argv)
{
	int year = 0;
    printf ("Koliko imate godina? ");
    
    scanf ("%i", &year);
    
    printf ("Vi imate %i godina \n", year); 
    
    ispisi (&year);
    
    
    //Na pocetku varijabla year oblika integera ima vrijednost nula. Scanf funkcijom omogucava se unos broja sa tipkovnice
    //na adresu varijable year. Printf funkcija ispisuje vrijednost varijable year
    
    system("PAUSE");
    return 0;
}
