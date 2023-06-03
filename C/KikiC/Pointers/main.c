#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{    
    int a = 5;    
    int *b = &a;  //pointer na (adresu) varijable a 
    
    printf("A = %i \n", a);
    printf("&A = %i \n", &a);

    printf("\n");

    printf("B = %i \n", b);
    printf("&B = %i \n", &b);
    printf("*B = %i \n", *b); //ispisi ono na sto b pointa (ne znaci pointer na b iako se jednako pise (*b))
    
    system("PAUSE");
    
	return 0;
}