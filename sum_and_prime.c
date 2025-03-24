#include <stdio.h>

int main() {
    int num, first_digit, second_digit, sum, is_prime = 1; 

    printf("Enter a number: ");
    scanf("%d", &num);

    first_digit = num / 10;
    second_digit = num % 10;
    sum = first_digit + second_digit;

    if (sum < 2) {
        is_prime = 0;  
    } else {
        for (int i = 2; i * i <= sum; i++) {
            if (sum % i == 0) {
                is_prime = 0;  
                break;
            }
        }
    }

    if (is_prime) {
        printf("The sum of digits '%d' is a prime number\n", sum);
    } else {
        printf("The sum of digits '%d' is not a prime number\n", sum);
    }

    return 0;
}