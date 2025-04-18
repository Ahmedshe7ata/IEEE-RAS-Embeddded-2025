#include <stdio.h>

int main() {
    int num1, num2, sum = 0;

   
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    
    if (num1 <= 0 || num2 <= 0) {
        printf("Both numbers must be positive.\n");
        return 1;     }

    
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    
    for (int i = num1; i <= num2; i++) {
        sum += i;
    }

        printf("The sum of all numbers from %d to %d = %d\n", num1, num2, sum);

    return 0;
}