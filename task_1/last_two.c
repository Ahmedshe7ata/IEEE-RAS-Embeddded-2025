#include <stdio.h>
int main() {
    int num1, num2, num3, num4, multy, last_two_digits;
    printf("enter the number1 :");
    scanf("%d", &num1);
     
    printf("enter the number2 :");
    scanf("%d", &num2);
    
    printf("enter the number3 :");
    scanf("%d", &num3);
    
    printf("enter the number4 :");
    scanf("%d", &num4);
    
    multy = num1 * num2 * num3 * num4;
    last_two_digits = multy % 100;
    
    printf("last two digits =%d", last_two_digits);
    return 0;
    
}   
    