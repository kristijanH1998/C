#include <stdio.h>

void swap(int v[], int i, int j)
{
    int temp = v[i];

    v[i] = v[j];
    
    v[j] = temp;
}


void qsort(int v[], int left, int right)
{
    if (left >= right) return;

    swap(v, left, (left + right) / 2);
    
    int last = left;

    for (int i = left + 1; i <= right; i++) {
        if(v[i] < v[left]) swap(v, ++last, i);
	}	
		
    swap(v, left, last);
    
    qsort(v, left, last-1);
    
    qsort(v, last + 1, right);
}


int main(void)
{
    printf("Unsorted Array\n");
	
	const int right = 9;
	int v[10] = {43, 53, 12, 64, 15, 67, 87, 10, 6, 90};

	for (int i = 0; i <= right; i++) {
		printf(" %d", v[i]);
	}	
		
	int left = 0;
    qsort(v, left, right);

    printf("\nSorted Array\n");
	
    for (int i = 0; i <= right; i++) {
        printf(" %d", v[i]);
	}
    
    return 0;
}
