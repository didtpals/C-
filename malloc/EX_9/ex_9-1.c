#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;
    scanf_s("%d", &num);

    int* arr = (int*)malloc(num * sizeof(int));
    
    if (arr == NULL) {
        printf("���� �Ҵ翡 �����Ͽ����ϴ�\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        arr[i] = i;
        printf("%d\n", arr[i]);
    }

    free(arr);
    return 0;
}