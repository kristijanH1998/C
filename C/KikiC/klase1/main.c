#include <stdio.h>
#include <stdlib.h>

typedef char* string;

struct Osoba
{
    string name;
    int dob;
    string adresa;   
    int godine_u_skoli;    
};

void ispisi(struct Osoba* osoba)  //struct Osoba je tip podatka, slicno kao npr. int, "Osoba" oznacava o kojoj stukturi (planu) je rijec
{
    printf("Ime   : %s\nGodine:%i\nAdresa: %s\nSkola godine: %i\n", 
        osoba->name,  //"->" oznacava dereferencijaciju elementa (atributa) strukture, kao i * kod primitiva (ugradjenog tipa, int, char...), pa se pod name npr za instancu kristijan ispisuje "Kristijan" itd
        osoba->dob, 
        osoba->adresa, 
        osoba->godine_u_skoli);
}

int main(int argc, char **argv)
{
    struct Osoba kristijan; // jedna od tri instance strukture, prati plan strukture
    kristijan.name = "Kristijan"; //instanca kristijan stukture Osoba dobiva vrijednost u obliku stringa "Kristijan" u svoj prvi atribut (name), naravno po planu strukture osoba
    kristijan.dob = 20;
    kristijan.adresa = "W ZEERING RD, Turlock, CA, USA";
    kristijan.godine_u_skoli = 10;
    
    //struct Osoba kristijan =
    //{
    //    .name = "Kristijan",
    //    .dob = 20,
    //    .adresa = "W ZEERING RD, Turlock, CA, USA",
    //    .godine_u_skoli = 10    
    //};
    
    ispisi(&kristijan);

    printf("\n");

    struct Osoba lolica;
    
    lolica.name = "Lorien";
    lolica.dob = 15;
    lolica.adresa = "Stosicevo setaliste 33, Orahovica, Croatia";
    lolica.godine_u_skoli = 15;
    
    ispisi(&lolica);

    printf("\n");
    
    struct Osoba marko;

    marko.name = "Marko";
    marko.dob = 45;
    marko.adresa = "Vrag ne zna 44, Orahovica, Croatia";
    marko.godine_u_skoli = 4;
    
    ispisi(&marko);
    
    system("PAUSE");
    
	return 0;
}