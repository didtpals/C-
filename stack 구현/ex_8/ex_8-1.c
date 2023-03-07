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

// 후위 표기법 수식 계산
int main(void) {
    char input[STACK_MAX_SIZE];
    int len;
    int num1;
    int num2;
    int result;
    Stack stack;

    stack.top = -1; // stack 초기화
    printf("후위 표기법으로 수식을 입력하세요 : ");
    fgets(input, sizeof(input), stdin); // 문자열을 입력 받기 위한 함수
    printf("\n< stack->top의 추가와 제거 과정 >\n\n");
    len = strlen(input); // 문자열의 길이를 변수에 저장

    // 입력한 수식을 확인하면서 연산자인 경우 stack에서 피연산지를 가져와 연산을 수행한다.
    // 피연산자인 경우 stack에 push한다.
    for (int i = 0; i < len; i++) { // 배열을 문자열의 길이보다 적을 때 까지 반복적으로 돌면서 요소를 확인
        if (input[i] >= '0' && input[i] <= '9') { // input이 받은 문자가 0~9 사이에 범위의 숫자라면 정수형으로 변환되어 push
            push(&stack, input[i] - '0'); // 문자의 ASCII값에서 0의 ASCII값을 빼서 정수로 바꿔준다.
        }
        else if (input[i] == '+' && !empty(&stack)) { // input 받은 문자가 '+'이거나 stack이 비워져있지 않다면 실행
            num1 = pop(&stack); // stack은 후입선출 개념이기 때문에 마지막으로 push된 값이 num2에 할당 된다.
            num2 = pop(&stack); // 덧셈에 필요한 두 개의 피연산자를 꺼낸다.
            push(&stack, num1 + num2); // 두 값을 더한 결과를 stack에 다시 push한다.
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

    if (!empty(&stack)) { // stack이 비어있지 않다면 실행
        result = pop(&stack); // stack의 최상위 배열의 값을 반환 받아 변수에 대입한다.
        printf("\n계산 결과 : %d\n", result); // 계산 결과 출력
    }
    return 0;
}

void push(Stack* stack, int value) {
    if (stack->top == STACK_MAX_SIZE - 1) { // stack이 가득차면 오버플로우 
        printf("Stack overflow\n");
        exit(1);
    }
    stack->stack_arr[++(stack->top)] = value; // 배열에 top을 추가하고 value 추가

    printf("          추가 top[%d] = %d\n", stack->top, stack->stack_arr[stack->top]);
}

// stack에 요소를 제거하고 반환하는 함수
int pop(Stack* stack) {
    if (stack->top == -1) { // stack이 비어있으면 언더플로우
        printf("Stack underflow\n");
        exit(1);
    }
    printf("          제거 top[%d] = %d\n", stack->top, stack->stack_arr[stack->top]); // 제거할 값을 출력

    return stack->stack_arr[(stack->top)--]; // 배열 최상위 top을 반환하고 최상위 top 제거
}

// stack이 비어있는지 확인
int empty(Stack* stack) {
    return stack->top == -1;
}