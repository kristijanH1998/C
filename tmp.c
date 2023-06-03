/* quicksort: example of recursive sorting 
  Developed by C.A.R. Hoare in 1962. Given an array,one element is chosen and the others are 
  partitioned into two subsets - those less than the partition element and those greater than or
  equal to it. The same process is then applied recursively to the two subsets. When a subset has fewer than two elements, it does not need any sorting; this stops the recursion */

#include <stdio.h>

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];

    v[i] = v[j];
    
    v[j] = temp;
}


void qsort(int v[], int left, int right)
{
    int i,last;
    
    if(left >= right) return;

    swap(v, left, (left+right) / 2);
    
    last = left;

    for (int i = left + 1; i <= right; i++) {
        if(v[i] < v[left]) swap(v, ++last, i);
	}	
		
    swap(v, left, last);
    
    qsort(v, left, last-1);
    
    qsort(v, last+1, right);
}


int main(void)
{
	int left = 0;
	int right = 9;
	int v[10] = {43,53,12,64,15,67,87,10,6,90};

    printf("Unsorted Array\n");
	
    for (int i = 0; i <= right; i++) {
		printf(" %d", v[i]);
	}	
		
    qsort(v, left, right);

    printf("\nSorted Array\n");
	
    for (int i = 0; i <= right; i++) {
        printf(" %d", v[i]);
	}
    
    return 0;
}

