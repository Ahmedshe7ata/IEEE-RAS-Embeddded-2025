#include <stdio.h>
int main() {
    int num, i=1;
    
    printf("enter the number");
    scanf("%d", &num);
    
    if(num <= 0)
    {
        return 1;
    }
    
    for(i=1; i<=num; i++)
    {
         if (num % i == 0) 
        { 
        
        printf("%d\n", i);
          
        }
           
    }
    
    return 0;
    
}   