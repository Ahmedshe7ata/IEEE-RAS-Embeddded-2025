#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    scanf("%d", &N);
    int i, j; 
    int a[N][N];
    for(i=0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
          scanf("%d", &a[i][j]);     
        }

    }
    
    int sum_1 = 0, x;
    for(i=0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
          if(i == j)
          {
            x = a[i][j];
            sum_1 = sum_1 + x;
              
          }
        }

    }
    
    int sum_2 = 0, y, Total;
    for(i=0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
          if(i + j == N - 1)
          {
            y = a[i][j];
            sum_2 = sum_2 + y;
              
          }
        }

    }
    
    Total = abs(sum_1 - sum_2); 
    
    printf("%d", Total);



    return 0;
}