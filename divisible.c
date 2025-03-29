#include <stdio.h>

void divisible(int a, int b){
    
    
    if(a % b == 0){
        printf("%d is divible by %d",a ,b);
    }
    else
    {
     printf("%d is not divible by %d",a ,b);   
    }
    
}

 
int main()
{
    int a, b;
    
    printf("Enter a and b:");
    scanf("%d %d",&a ,&b);
    
    divisible(a ,b);

    return 0;
}
