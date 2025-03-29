#include <stdio.h>

void armstrong(int num)
{
    int original_num ,first_digit, second_digit, third_digit, sum;
    for(num=1; num<1000; num++)
    {
         original_num = num;
    
         first_digit = num / 100;
    
         second_digit = (num % 100) /10;
    
         third_digit = num % 10;
    
         sum = (first_digit * first_digit * first_digit) + 
         (second_digit * second_digit * second_digit) + 
         (third_digit * third_digit * third_digit);

    
        if(sum == num)
          {
            printf("%d\n", num);
          }
            
        
    } 
        
} 
    
int main()
{
    
    int num;
    
    armstrong(num);

    return 0;
}