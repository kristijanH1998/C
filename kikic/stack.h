#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct StackElement {
	void *next;
	void *value;
};

struct Stack {
	struct StackElement *first;
	size_t size;
};

void push_int(struct Stack *stack, int value);
void push_float (struct Stack *stack, float value);

int pop_int(struct Stack *stack);
float pop_float(struct Stack *stack);

#endif /** STACK_H */
