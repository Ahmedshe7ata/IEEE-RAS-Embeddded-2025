#include<stdio.h>
#include<stdlib.h>


int main()
{
    int i;
    int *ptr = (int *)malloc(2*sizeof(int));

    if (ptr == NULL)
    {
        printf("memory not available");
        exit(1);
    }

    printf("enter two numbers :");
    for(i=0; i<2; i++)
    {
        scanf("%d", ptr+i);
    }

    ptr =(int *)realloc(ptr, 4*sizeof(int));
    if (ptr == NULL)
    {
        printf("memory not available");
        exit(1);
    }
    
    printf("enter two more numbers :");
    for(i=2; i<4; i++)
    {
        scanf("%d", ptr+i);
    }

    for(i=0; i<4; i++)
    {
        printf(" from malloc and realloc :%d", *(ptr+i));
    }

    int *ptr2 = (int *)calloc(3, sizeof(int));
    if (ptr2 == NULL)
    {
        printf("memory not available");
        exit(1);
    }

    printf("enter three numbers :");
    for(i=0; i<3; i++)
    {
        scanf("%d", ptr+i);
    }

    for(i=0; i<3; i++)
    {
        printf(" from calloc :%d ", *(ptr+i));
    }



    free(ptr);
    free(ptr2);
   return 0;
}

