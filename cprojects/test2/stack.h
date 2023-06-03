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

void push_int(struct Stack *, int);
void push_float (struct Stack *, float);

int pop_int(struct Stack *);
float pop_float(struct Stack *);

#endif /** STACK_H */
