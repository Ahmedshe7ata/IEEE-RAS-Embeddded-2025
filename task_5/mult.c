#include <stdio.h>

int main()
{
    int i, j;
  int arr1[3][3];
  int arr2[3][3];
  int *c;
  
  
  for(i=0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
          scanf("%d", &arr1[i][j]);     
        }

    }
    
    for(i=0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
          scanf("%d", &arr2[i][j]);     
        }

    }
    int result[3][3];
    int *ptr1 = &arr1[0][0];
    int *ptr2 = &arr2[0][0];

    for (int i = 0; i < 3; i++) {       
        for (int j = 0; j < 3; j++) {   
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                
                result[i][j] += (*(ptr1 + i * 3 + k)) * (*(ptr2 + k * 3 + j));
            }
        }
    }

    
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", result[i][j]);
        }
        printf("\n");
    }
    
    
    
   
    

    return 0;
}