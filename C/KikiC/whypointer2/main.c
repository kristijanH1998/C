#include <stdio.h>

void ispisi_by_value(int number[]) // copy by value i trosenje jos 12 byte (3 x 4)
{
    printf("%i\n", number[0]);
    printf("%i\n", number[1]);
    printf("%i\n", number[2]);
}

void ispisi_by_ref(int* number) // copy by ref i NEMA trosenja jos 12 byte (3 x 4)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", *(number + i));
    }
//    printf("%i\n", number[0]);
//    printf("%i\n", number[1]);
//    printf("%i\n", number[2]);
}

int main(int argc, char **argv)
{
    int a[] = { 15, 6, 1998 };
    
    //ispisi_by_value(a);
    
    ispisi_by_ref(&a[0]);

    system("PAUSE");
    
	return 0;
}
