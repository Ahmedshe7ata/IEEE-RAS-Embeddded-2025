#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int odd[100]; 
    int count = 0;
    
    int *p = arr;     
    int *q = odd;      

    for (int i = 0; i < size; i++) {
        if (*(p + i) % 2 != 0) {
            *(q + count) = *(p + i);
            count++;
        }
    }

    printf("Odd numbers are: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(q + i));
    }

    printf("\nTotal odd numbers: %d\n", count);

    return 0;
}