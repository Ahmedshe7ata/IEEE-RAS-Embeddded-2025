#include<stdio.h>
#define addition

#define add_nums(x, y) ((x)+(y))
#define sub_nums(x, y) ((x)-(y))

int main()
{
    int a, b, result;
    printf("enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    #ifdef addition
       result = add_nums(a,b);
       printf("%d", result);
    #elif defined substract
       result = sub_nums(a, b);
       printf("%d", result);
    #else 
       printf("no operation defined");
    #endif
    
    return 0;

}
