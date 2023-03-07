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

// ���� ǥ��� ���� ���
int main(void) {
    char input[STACK_MAX_SIZE];
    int len;
    int num1;
    int num2;
    int result;
    Stack stack;

    stack.top = -1; // stack �ʱ�ȭ
    printf("���� ǥ������� ������ �Է��ϼ��� : ");
    fgets(input, sizeof(input), stdin); // ���ڿ��� �Է� �ޱ� ���� �Լ�
    printf("\n< stack->top�� �߰��� ���� ���� >\n\n");
    len = strlen(input); // ���ڿ��� ���̸� ������ ����

    // �Է��� ������ Ȯ���ϸ鼭 �������� ��� stack���� �ǿ������� ������ ������ �����Ѵ�.
    // �ǿ������� ��� stack�� push�Ѵ�.
    for (int i = 0; i < len; i++) { // �迭�� ���ڿ��� ���̺��� ���� �� ���� �ݺ������� ���鼭 ��Ҹ� Ȯ��
        if (input[i] >= '0' && input[i] <= '9') { // input�� ���� ���ڰ� 0~9 ���̿� ������ ���ڶ�� ���������� ��ȯ�Ǿ� push
            push(&stack, input[i] - '0'); // ������ ASCII������ 0�� ASCII���� ���� ������ �ٲ��ش�.
        }
        else if (input[i] == '+' && !empty(&stack)) { // input ���� ���ڰ� '+'�̰ų� stack�� ��������� �ʴٸ� ����
            num1 = pop(&stack); // stack�� ���Լ��� �����̱� ������ ���������� push�� ���� num2�� �Ҵ� �ȴ�.
            num2 = pop(&stack); // ������ �ʿ��� �� ���� �ǿ����ڸ� ������.
            push(&stack, num1 + num2); // �� ���� ���� ����� stack�� �ٽ� push�Ѵ�.
        }
        else if (input[i] == '-' && !empty(&stack)) {
            num2 = pop(&stack);
            num1 = pop(&stack);
            push(&stack, num1 - num2);
        }
        else if (input[i] == '*' && !empty(&stack)) {
            num2 = pop(&stack);
            num1 = pop(&stack);
            push(&stack, num1 * num2);
        }
        else if (input[i] == '/' && !empty(&stack)) {
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
    if (stack->top == STACK_MAX_SIZE - 1) { // stack�� �������� �����÷ο� 
        printf("Stack overflow\n");
        exit(1);
    }
    stack->stack_arr[++(stack->top)] = value; // �迭�� top�� �߰��ϰ� value �߰�

    printf("          �߰� top[%d] = %d\n", stack->top, stack->stack_arr[stack->top]);
}

// stack�� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
int pop(Stack* stack) {
    if (stack->top == -1) { // stack�� ��������� ����÷ο�
        printf("Stack underflow\n");
        exit(1);
    }
    printf("          ���� top[%d] = %d\n", stack->top, stack->stack_arr[stack->top]); // ������ ���� ���

    return stack->stack_arr[(stack->top)--]; // �迭 �ֻ��� top�� ��ȯ�ϰ� �ֻ��� top ����
}

// stack�� ����ִ��� Ȯ��
int empty(Stack* stack) {
    return stack->top == -1;
}