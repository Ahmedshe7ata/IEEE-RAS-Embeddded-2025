#include <stdio.h>
int main()
{
    int num, max, min, n=1000, i;
    printf("enter number :");
    scanf("%d", &num); 
    
    max = min = num;
    
    
      while (1) {
       printf("enter number :"); 
       scanf("%d", &num);
       if(num == -1) break;
       if(num > max)
        {
            max = num;
        }
        if(num < min)
        {
            min = num;
        }
        
      } 
      
    printf("max_number :%d\n", max);
    printf("min_number :%d", min);
return 0;
}