#include <stdio.h>

int global;
static int global_static;

int main(void) {
    int result = 10;

    printf("%d\n", result + global + global_static);
    return 0;
}