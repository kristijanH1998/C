#include <stdio.h>

struct Zaposlenik
{ 
    char* ime;
    int dob;
    char* obrazovanje;
    int godine_radnog_iskustva;
    
};

int godine_obrazovanja (struct Zaposlenik* covjek) //za razliku od void funkcije koja bi sama kroz printf u sebi prikazivala godine obrazovanja, dok ova funkcija vraca mainu te godine (taj rezultat oduzimanja) i main ih ispisuje kroz printf
{
    return (covjek->dob - covjek->godine_radnog_iskustva);
    
    
    
    
}







int main(int argc, char **argv)
{
    struct Zaposlenik prvi;
    prvi.ime = "ADFG";
    prvi.dob = 34;
    prvi.obrazovanje = "College1";
    prvi.godine_radnog_iskustva = 9;
    
    //int a = godine_obrazovanja (&prvi)    //rezultat funkcije godine_obrazovanja stavlja se u varijablu a
            
    //printf ("Trajanje procesa obrazovanja je %i \n", a); //ispis onoga sto je u varijabli a
    
	printf ("Trajanje procesa obrazovanja je %i godina \n", godine_obrazovanja (&prvi)); //spremljeno u privremenu varijablu radi slanja printf-u, "godine_obrazovanja (&prvi)" je poziv funkcije i ujedno i slanje parametra  (koji funkcija vraca) printf-u, printf-u se salju dvije stvari, jedan tekst (u navodnicima, "Trajanje procesa obrazovanja je %i godina \n") i ono sto funkcija godine_obrazovanja vraca
    
    
    system("PAUSE");
    return 0;
}
