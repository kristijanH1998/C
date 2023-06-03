#include <stdio.h>



int binsearch (int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	if (x == v[mid]){  //dodan uvjet
		return mid;
	}
	while ((low <= high) && (x != v[mid])){
		
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
		mid = (low + high) / 2;		
	}
	if ((low > high) && (v[mid] != x))  //dodan uvjet
		return -1;
	else 
		return mid;		
}

int main(void){
	
	int ar[] = {1, 7, 8, 9, 11, 12, 25, 28, 33, 45};
	
	printf (" %i", binsearch (9, ar, 10));

	return 0;
}