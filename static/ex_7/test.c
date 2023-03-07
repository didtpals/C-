#include <stdio.h>
#include <stdlib.h>

int main() {
    int* p;
    p = (int*)malloc(sizeof(int));

    if (p == NULL) {
        printf("Error: out of memory.\n");
        exit(1);
    }

    *p = 42;

    printf("포인터 변수 p의 값 :  %d\n", *p);

    free(p);

    return 0;
}