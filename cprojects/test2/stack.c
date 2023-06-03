#include "stack.h"

void push_int(struct Stack *stack, int value) {
	struct StackElement *se = calloc(1, sizeof(struct StackElement));
	se->next = stack->first;
    {
        int *v = malloc(sizeof(int));
        *v = value;

        se->value = v;
    }
	//int *v = malloc(sizeof(int));
	//*v = value;

	//se->value = v;     //this "value" is a pointer, not the one that is sent to push_int as an argument; this line
	//puts pointer v into pointer value (SE's value pointer)
	stack->first = se;
	stack->size++;
}

int pop_int(struct Stack *stack) {
	if (stack->size == 0) return -1;

	int *value = (int*)stack->first->value;
	stack->first = stack->first->next;
	stack->size--;

	return *value;
}

void push_float (struct Stack *stack, float value){
	struct StackElement *se = calloc(1, sizeof(struct StackElement));
	se->next = stack->first;

	float *v = malloc(sizeof(float));
	*v = value;                   // put "value" into what v points to

	se->value = v;
	stack->first = se;
	stack->size++;
}

float pop_float(struct Stack *stack) {
	if (stack->size == 0) return -1;

	float *value = (float*)stack->first->value;
	stack->first = stack->first->next;
	stack->size--;

	return *value;
}
