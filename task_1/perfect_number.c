#include <stdio.h>

int main() {
    int num, i = 1, sum = 0;  
    
    printf("Enter the number: ");
    scanf("%d", &num);

    
    if (num <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    
    while (i < num) {  
        if (num % i == 0) { 
            sum += i;  
        }
        i++;  
    }

    
    if (sum == num) {  
        printf("%d is a perfect number\n", num);
    } else {
        printf("%d is not a perfect number\n", num);
    }

    return 0;
}