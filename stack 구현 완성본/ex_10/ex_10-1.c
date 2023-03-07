#include <stdio.h> // fgets ���
#include <stdlib.h> // strlen ���
#include <string.h> // exit ���

// stack�� �ִ� ũ�� ����
#define STACK_MAX_SIZE 100

// stack ����ü
typedef struct {
    int top; // stack�� ���� ���� �ִ� ����� �ε����� �����ϴ� ����
    int stack_arr[STACK_MAX_SIZE]; // stack�� ��Ҹ� �����ϴ� �迭
} Stack;

// stack ���� �Լ�
void push(Stack* stack, int value); // ��� �߰�
int pop(Stack* stack); // ��� ����
int empty(Stack* stack); // ����ִ��� Ȯ��
void infix_to_postfix(char* infix, char* postfix); // ���� -> ���� ��ȯ
int priority(char op); // ������ �켱���� ��
char peek(Stack* stack); // ���� �ֻ��� ��ȯ

// ���� ǥ��� ���� ���
int main(void) {
    char infix[STACK_MAX_SIZE];
    char postfix[STACK_MAX_SIZE];
    int len;
    int num1;
    int num2;
    int result;
    Stack stack;

    stack.top = -1; // stack �ʱ�ȭ
    printf("���� ǥ������� ������ �Է��ϼ��� : ");
    fgets(infix, sizeof(infix), stdin); // infix ���ڿ� �Է�
    printf("\n");

    infix_to_postfix(infix, postfix); // ���� ǥ�⸦ ���� ǥ��� ��ȯ

    printf("\n��ȯ�� ���� ǥ��� : %s\n", postfix);
    printf("\n< stack->top�� �߰��� ���� ���� >\n\n");
    len = strlen(postfix);

    for (int i = 0; i < len; i++) { // �迭�� ���ڿ��� ���̺��� ���� �� ���� �ݺ������� ���鼭 ��Ҹ� Ȯ��
        if (postfix[i] >= '0' && postfix[i] <= '9') { // input�� ���� ���ڰ� 0~9 ���̿� ������ ���ڶ�� ���������� ��ȯ�Ǿ� push
            push(&stack, postfix[i] - '0'); // ������ ASCII������ 0�� ASCII���� ���� ������ �ٲ��ش�.
        }
        else if (postfix[i] == '+' && !empty(&stack)) { // input ���� ���ڰ� '+'�̰ų� stack�� ��������� �ʴٸ� ����
            num1 = pop(&stack); // stack�� ���Լ��� �����̱� ������ ���������� push�� ���� num2�� �Ҵ� �ȴ�.
            num2 = pop(&stack); // ������ �ʿ��� �� ���� �ǿ����ڸ� ������.
            push(&stack, num1 + num2); // �� ���� ���� ����� stack�� �ٽ� push�Ѵ�.
        }
        else if (postfix[i] == '-' && !empty(&stack)) {
            num2 = pop(&stack);
            num1 = pop(&stack);
            push(&stack, num1 - num2);
        }
        else if (postfix[i] == '*' && !empty(&stack)) {
            num2 = pop(&stack);
            num1 = pop(&stack);
            push(&stack, num1 * num2);
        }
        else if (postfix[i] == '/' && !empty(&stack)) {
            num2 = pop(&stack);
            num1 = pop(&stack);
            push(&stack, num1 / num2);
        }
    }

    if (!empty(&stack)) { // stack�� ������� �ʴٸ� ����
        result = pop(&stack); // stack�� �ֻ��� �迭�� ���� ��ȯ �޾� ������ �����Ѵ�.
        printf("\n��� ��� : %d\n", result); // ��� ��� ���
    }
    return 0;
}

void push(Stack* stack, int value) {
    if (stack->top == STACK_MAX_SIZE - 1) {
        printf("Stack overflow!\n"); // stack�� �������� �����÷ο� ���
        exit(1);
    }
    stack->stack_arr[++(stack->top)] = value; // �迭�� top�� �߰��ϰ� value �߰�

    printf("          �߰� top[%d] : %d\n", stack->top, value);
}

// stack�� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n"); // stack�� ��������� ����÷ο� ���
        exit(1);
    }
    printf("          ���� top[%d]\n", stack->top);

    return stack->stack_arr[(stack->top)--]; // �迭 �ֻ��� top�� ��ȯ�ϰ� �ֻ��� top ����
}

// stack�� ����ִ��� Ȯ��
int empty(Stack* stack) {
    return stack->top == -1;
}

// ������ �ֻ��� �� ��ȯ
char peek(Stack* stack) {
    if (stack->top == -1) { // ������ ����ִ� ���
        printf("Stack underflow!\n");
        exit(1);
    }
    else {
        return stack->stack_arr[stack->top]; // ������ �� ���� �ִ� ���� ��ȯ
    }
}

// ������ �켱������ ��ȯ�ϴ� �Լ�
int priority(char oper) { 
    if (oper == '*' || oper == '/') return 2;
    else if (oper== '+' || oper == '-') return 1;
}

// ���� ǥ�⸦ ���� ǥ��� ��ȯ
void infix_to_postfix(char* infix, char* postfix) {
    Stack stack;
    int len = strlen(infix);
    int index = 0;
    stack.top = -1;

    for (int i = 0; i < len; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[index++] = infix[i]; // ���ڰ� �ǿ������� ��� postfix ���ڿ��� �߰�
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!empty(&stack) && priority(infix[i]) <= priority(peek(&stack))) { // ������ �켱���� ��
                postfix[index++] = pop(&stack); // �����ڸ� ��� Ȯ���ϰ� postfix ���ڿ��� �߰�
            }
                push(&stack, infix[i]); // ���ڰ� �������� ��� stack�� �߰�
        }
    }

    while (!empty(&stack)) {
        postfix[index++] = pop(&stack); // ���ڿ��� ��� Ȯ���ϰ� stack�� �����ִ� �����ڵ��� ��� pop�ϰ� postfix ���ڿ��� �߰�
    }

    postfix[index] = NULL; // NULL ���ڸ� postfix ���ڿ��� �������� �߰�
}