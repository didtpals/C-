#include <stdio.h>

void func();

int main(void){
    func();  
    func();   
    func();   
    return 0;
}

void func() {
    static int count = 0;
    count++;
    printf("count�� ��: %d\n", count);
}