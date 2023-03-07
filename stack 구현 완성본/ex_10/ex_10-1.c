#include <stdio.h> // fgets 사용
#include <stdlib.h> // strlen 사용
#include <string.h> // exit 사용

// stack의 최대 크기 지정
#define STACK_MAX_SIZE 100

// stack 구조체
typedef struct {
    int top; // stack의 가장 위에 있는 요소의 인덱스를 저장하는 변수
    int stack_arr[STACK_MAX_SIZE]; // stack의 요소를 저장하는 배열
} Stack;

// stack 구현 함수
void push(Stack* stack, int value); // 요소 추가
int pop(Stack* stack); // 요소 제거
int empty(Stack* stack); // 비어있는지 확인
void infix_to_postfix(char* infix, char* postfix); // 중위 -> 후위 변환
int priority(char op); // 연산자 우선순위 비교
char peek(Stack* stack); // 스택 최상위 반환

// 후위 표기법 수식 계산
int main(void) {
    char infix[STACK_MAX_SIZE];
    char postfix[STACK_MAX_SIZE];
    int len;
    int num1;
    int num2;
    int result;
    Stack stack;

    stack.top = -1; // stack 초기화
    printf("중위 표기법으로 수식을 입력하세요 : ");
    fgets(infix, sizeof(infix), stdin); // infix 문자열 입력
    printf("\n");

    infix_to_postfix(infix, postfix); // 중위 표기를 후위 표기로 변환

    printf("\n변환된 후위 표기법 : %s\n", postfix);
    printf("\n< stack->top의 추가와 제거 과정 >\n\n");
    len = strlen(postfix);

    for (int i = 0; i < len; i++) { // 배열을 문자열의 길이보다 적을 때 까지 반복적으로 돌면서 요소를 확인
        if (postfix[i] >= '0' && postfix[i] <= '9') { // input이 받은 문자가 0~9 사이에 범위의 숫자라면 정수형으로 변환되어 push
            push(&stack, postfix[i] - '0'); // 문자의 ASCII값에서 0의 ASCII값을 빼서 정수로 바꿔준다.
        }
        else if (postfix[i] == '+' && !empty(&stack)) { // input 받은 문자가 '+'이거나 stack이 비워져있지 않다면 실행
            num1 = pop(&stack); // stack은 후입선출 개념이기 때문에 마지막으로 push된 값이 num2에 할당 된다.
            num2 = pop(&stack); // 덧셈에 필요한 두 개의 피연산자를 꺼낸다.
            push(&stack, num1 + num2); // 두 값을 더한 결과를 stack에 다시 push한다.
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

    if (!empty(&stack)) { // stack이 비어있지 않다면 실행
        result = pop(&stack); // stack의 최상위 배열의 값을 반환 받아 변수에 대입한다.
        printf("\n계산 결과 : %d\n", result); // 계산 결과 출력
    }
    return 0;
}

void push(Stack* stack, int value) {
    if (stack->top == STACK_MAX_SIZE - 1) {
        printf("Stack overflow!\n"); // stack이 가득차면 오버플로우 출력
        exit(1);
    }
    stack->stack_arr[++(stack->top)] = value; // 배열에 top을 추가하고 value 추가

    printf("          추가 top[%d] : %d\n", stack->top, value);
}

// stack에 요소를 제거하고 반환하는 함수
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n"); // stack이 비어있으면 언더플로우 출력
        exit(1);
    }
    printf("          제거 top[%d]\n", stack->top);

    return stack->stack_arr[(stack->top)--]; // 배열 최상위 top을 반환하고 최상위 top 제거
}

// stack이 비어있는지 확인
int empty(Stack* stack) {
    return stack->top == -1;
}

// 스택의 최상위 값 반환
char peek(Stack* stack) {
    if (stack->top == -1) { // 스택이 비어있는 경우
        printf("Stack underflow!\n");
        exit(1);
    }
    else {
        return stack->stack_arr[stack->top]; // 스택의 맨 위에 있는 값을 반환
    }
}

// 연산자 우선순위를 반환하는 함수
int priority(char oper) { 
    if (oper == '*' || oper == '/') return 2;
    else if (oper== '+' || oper == '-') return 1;
}

// 중위 표기를 후위 표기로 변환
void infix_to_postfix(char* infix, char* postfix) {
    Stack stack;
    int len = strlen(infix);
    int index = 0;
    stack.top = -1;

    for (int i = 0; i < len; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[index++] = infix[i]; // 문자가 피연산자인 경우 postfix 문자열에 추가
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!empty(&stack) && priority(infix[i]) <= priority(peek(&stack))) { // 연산자 우선순위 비교
                postfix[index++] = pop(&stack); // 연산자를 모두 확인하고 postfix 문자열에 추가
            }
                push(&stack, infix[i]); // 문자가 연산자인 경우 stack에 추가
        }
    }

    while (!empty(&stack)) {
        postfix[index++] = pop(&stack); // 문자열을 모두 확인하고 stack에 남아있는 연산자들을 모두 pop하고 postfix 문자열에 추가
    }

    postfix[index] = NULL; // NULL 문자를 postfix 문자열의 마지막에 추가
}