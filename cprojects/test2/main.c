#include <stdio.h>
#include "stack.h"

void qqsort(int v[],int left,int right, struct Stack *stack, int auxar[]);
void swap(int v[],int i,int j);

int main(void)
{
	struct Stack stack = { .size = 0 };

//printf("Stack size:%i\n", stack.size);

//push_float(&stack, 1.45f);
//push_float(&stack, 2.1f);
//push_float(&stack, 32.42f);
//push_float(&stack, 4.39f);
//push_float(&stack, 5.0f);

//printf("Stack size:%i\n", stack.size);

//printf("%i\n", pop_int(&stack));
//printf("%i\n", pop_int(&stack));
//printf("%i\n", pop_int(&stack));
//printf("%i\n", pop_int(&stack));
//printf("%i\n", pop_int(&stack));

// Pop all, stop if pop returns -1 (stack empty)
//for (float value = 0; (value = pop_float(&stack)) != -1; ) {
//printf("%f\n", value);
//}

//printf("Stack size:%i\n", stack.size);

    int i,left,right,v[7]={7, 77, 43, 12, 1, 0, 1345};
    int auxar[100];
    left=0;
    right=6;

    printf("Unsorted Array\n");
    for(i=0;i<=6;i++) {
        printf(" %d",v[i]);
    }
    printf("\n");
    qqsort(v,left,right,&stack,auxar);

    printf("\nSorted Array\n");
    for(i=0;i<=6;i++) {
        printf(" %d",v[i]);
	}

    return 0;
    getchar();
}

void qqsort(int v[],int left,int right, struct Stack *stack, int auxar[])
{
	int auxcount = 0;
	//int count2 = 0;
	//int count3 = 0;
	int successful = 0;
    push_int(stack, left);
    push_int(stack, right);

    label1:
    auxcount = 0;
    //successful = 0;
    while ((stack->size) != 0) {
		auxar[auxcount] = pop_int(stack);
		auxcount++;
	}
	int count2 = auxcount-1;
	int count3 = count2;

	label3:
	while (count2 >= 0){

		left = auxar[count2];
		right = auxar[count2-1];
		count2 = count2 - 2;
		goto label2;
    }
    if (successful == 0){
    	printf ("Array is sorted.");
    	return;
	} else {
		successful = 0;
		goto label1;
	}

	//Partitioning part:
	label2: ;
	int i,last;

    if(left>=right){
    	count3=count3-2;
        goto label3;
	}
	successful++;
    swap(v,left,(left+right)/2);

    last=left;

    for(i=left+1;i<=right;i++)
        if(v[i] < v[left])
            swap(v,++last,i);
    swap(v,left,last);

    if (last == left) {
    	push_int(stack, last+1);
    	push_int(stack, auxar[count3-1]);
    	count3 = count3 - 2;
    }
	if (last == right){
		push_int(stack, auxar[count3]);
    	push_int(stack, last-1);
    	count3 = count3 - 2;
	} else {
		push_int(stack, auxar[count3]);
    	push_int(stack, last-1);
    	push_int(stack, last+1);
    	push_int(stack, auxar[count3-1]);
    	count3 = count3 - 2;
	}
	goto label3;
}

/* swap: interchange v[i] and v[j] */

void swap(int v[],int i,int j)
{
    int temp;

    temp = v[i];

    v[i] = v[j];

    v[j] = temp;
}
