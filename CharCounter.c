#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void convertStr (char *str1){
	if (str1 == ""){
		return;
	}
	if (str1 == NULL){
		return;
	}

	
	
	char c = 0;
	int size = strlen(str1);
	
	char *str2 = malloc ((sizeof (char) * size) + 1);
	
	//char str2[size]; 
	
	
	for (int i = 0; i < (size + 1); i++){
		c = *(str1 + i);
		switch (c){
			case '\t':
				*(str2 + i) = 'X';
				break;	
			case '\n':
				*(str2 + i) = 'Y';
				break;
			default:
				*(str2 + i) = c;
				break;
			}
		if (i == size) {
			*(str2 + i) = '\0';
		}	
			
	}
	
	
	
	printf (" %s", str2);
	free (str2);
	str2 = NULL;
	
	
} 
int main(void){

	char *str1 = "	";
	
    convertStr (str1);
	
	return 0;
}