#include <stdio.h>

void shellsort (int v[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2){
		for (int i = gap; i < n; i++){
			for (int j = i - gap; j >= 0 && v[j] > v[j + gap]; j-=gap){
				int temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
	for (int a = 0; a < n; a++){
		printf(" %d", v[a]);
	} 		
}
int main(void){
	
	
	int array[] = {3,45,2,12,564,21,53,4,5,10};
	shellsort (array, 10);
	return 0;
}