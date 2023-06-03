#include <stdio.h>

void uvecajBrojZaJedan(int* number) // primi ono sto je na adresi onog sto je poslano (adresa od a ili &a je poslana)
{
    *number = *number + 1; // i to uveca za 1
}

int main(int argc, char **argv)
{
    int a = 5;
    
    uvecajBrojZaJedan(&a); //
    
    printf("%i\n", a); //prikazi u formatu integer "i", "\n" je da doda nakon ispisa jednu liniju 
    
    system("PAUSE");

	return 0;
}
