#include<stdio.h>

void qsort(int v[],int left,int right);
void swap(int v[],int i,int j);

int main(void)
{
    int i,left,right,v[10]={43,53,12,64,15,67,87,10,6,90};
    left=0;
    right=9;

    printf("Unsorted Array\n");
    for(i=0;i<=9;++i)
        printf(" %d",v[i]);
    qsort(v,left,right);

    printf("\nSorted Array\n");
    for(i=0;i<=9;++i)
        printf(" %d",v[i]);
    
    return 0;
}

void qsort(int v[],int left,int right)
{
    int i,last;
    
    if(left>=right)
        return;

    swap(v,left,(left+right)/2);
    
    last=left;

    for(i=left+1;i<=right;i++)
        if(v[i] < v[left])
            swap(v,++last,i);
    swap(v,left,last);
    
    qsort(v,left,last-1);
    
    qsort(v,last+1,right);
}

/* swap: interchange v[i] and v[j] */

void swap(int v[],int i,int j)
{
    int temp;

    temp = v[i];

    v[i] = v[j];
    
    v[j] = temp;
}