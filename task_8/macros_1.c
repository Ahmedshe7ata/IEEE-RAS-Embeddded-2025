#include <stdio.h>
#define SIZE 4
#define ascending

void input_nums (int numbers[], int size)
{
    printf("enter your numbers: ");
    int i;
    for(i=0; i < size; i++)
    {
        scanf("%d", &numbers[i]);

    };
    
}

void ascending_sort(int numbers[], int size)
{
    int i, j;
   for(i=0; i < size - 1; i++)
   {
       for(j=0; j < size - 1; j++)
       {
          if(numbers[j] < numbers[j+1]) 
          {
            int temp;
            temp = numbers[j];
            numbers[j] = numbers[j+1];
            numbers[j+1] = temp; 

          }
       }
   }   
}


void descending_sort(int numbers[], int size)
{
    int i, j;
   for(i=0; i < size - 1; i++)
   {
       for(j=0; j < size - 1; j++)
       {
          if(numbers[j] > numbers[j+1]) 
          {
            int temp;
            temp = numbers[j];
            numbers[j] = numbers[j+1];
            numbers[j+1] = temp; 

          }
       }
   }   
}


void print_nums (int numbers[], int size)
{
    printf("\nsorting:\n");
    int i;

    for(i=0; i < size; i++)
    {
        printf("%d\n", numbers[i]);
    };
    
}



int main()  
{
    int arr[SIZE];

    input_nums(arr, SIZE);
    #ifdef ascending
       ascending_sort(arr, SIZE);
    #elif defined descending
       descending_sort(arr, SIZE); 
    #else
        printf("not sorting defined.") ;
    #endif

    print_nums(arr, SIZE);    
 
    return 0;
}