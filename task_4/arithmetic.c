#include <stdio.h>
int main()
{

    int x, y;
    int  *ptr_1;
    int  *ptr_2;
    
    ptr_1 = &x;
    ptr_2 = &y;
    
    scanf("%d %d", ptr_1, ptr_2);
    printf("-------------------\n");
    
    printf("sum = %d\n", *ptr_1 + *ptr_2);
    printf("difference = %d\n", *ptr_1 - *ptr_2);
    printf("product = %d\n", (*ptr_1) * (*ptr_2));
    printf("Quotient = %d", (*ptr_1) / (*ptr_2));
    
  return 0;
}