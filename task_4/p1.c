#include <stdio.h>
int main()
{

    int x = 10;
    float y = 2.5;
    double z = 2.625;
    char n = 'c';
    
    int  *ptr_1;
    float  *ptr_2;
    double  *ptr_3;
    char  *ptr_4;
    
    ptr_1 = &x;
    ptr_2 = &y;
    ptr_3 = &z;
    ptr_4 = &n;
    

    printf("adress of x = %p\n", ptr_1);
    printf("adress of y = %p\n", ptr_2);
    printf("adress of z = %p\n", ptr_3);
    printf("adress of n = %p\n", ptr_4);
    
    printf("-------------------\n");
    
    printf("x = %d\n", *ptr_1);
    printf("y = %f\n", *ptr_2);
    printf("z = %lf\n", *ptr_3);
    printf("z = %c", *ptr_4);
    


    


  return 0;
}