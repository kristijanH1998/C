#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse (char *s, int q, int b);

void itob(int n, char *s, int b, int q){
	
	int num = n;
	if (n < 0){
		n = -n;
	}
	
	int i = 0;
	int j;
	while (n > 0){
		j = n % b;
		if (j <= 9){
			*(s + i) = j + '0';
		} else {
			*(s + i) = (char) (j + 55);
		}
		
		n = n / b;
		i++;
	} 
	
	if (num < 0){
		*(s + i) = '-';
		i++; 
	}
	
	*(s + i) = '\0';
	reverse (s, q, b);
}

void reverse (char *s, int q, int b){
	
	int i, j, t;
	for (i = 0, j = q - 1; i < j; i++, j--){
		t = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = t;
	}
	printf ("The number you entered "
	"represented in base %d is: %s", b, s);
}

int main(void){

	int n, base, test;
	int q = 0;
	
	printf ("Enter the number: \n");
	scanf ("%d", &n);
	printf ("Enter the base (greater than 1) to convert that number to: \n");
	
	scanf ("%d", &base);
	
	while (base < 2){
		printf ("Try again.\n");
		scanf ("%d", &base);
	}
	
	test = n;
	
	while (test > 0){
		test = test / base;
		q++;
    } 
	
	char *s = malloc ((sizeof(char) * q) + 1);
	
	itob (n, s, base, q);
	
	return 0;		
}

