#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 100

typedef struct {
	int top;
	int stack_arr[STACK_MAX_SIZE];
}Stack;

int init(Stack* stack) {
	stack->top = -1;
 }

int empty(Stack* stack) {
	if (stack->top == -1) {
		return 1;
	}
	return 0;
}

int full(Stack* stack) {
	if (stack->top == STACK_MAX_SIZE - 1) {
		return 1;
	}
	return 0;
}

void push(Stack* stack, int value) {
	if (full(stack)) {
		printf("stack is full");
		exit(1);
	}
	printf("추가 %d\n", value);
	stack->stack_arr[++(stack->top)] = value;
}

int pop(Stack* stack) {
	if (empty(stack)) {
		printf("stack is empty");
		exit(1);
	}
	printf("제거");
	return stack->stack_arr[(stack->top)--];
}

int peek(Stack* stack) {
	if (empty(stack)) {
		printf("stack is empty");
	}
	printf("\n최상단");
	return stack->stack_arr[(stack->top)];
}

int main(void) {
	Stack stack;
	init(&stack);

	push(&stack, 3);
	push(&stack, 2);
	push(&stack, 1);

	printf(" : %d\n\n", peek(&stack));
	printf(" : %d\n", pop(&stack));
	printf(" : %d\n", pop(&stack));
	printf(" : %d\n", pop(&stack));

	printf("pop : %d\n", pop(&stack));
	return 0;
}