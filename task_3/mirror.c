#include<stdio.h>
int main()
{
   int N, M;
   scanf("%d %d", &N, &M);
   int i, j; 
    int a[N][M];
    for(i=0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
          scanf("%d", &a[i][j]);     
        }

    }
     
    
        for(int i = 0; i < N; i++) 
        {
             for(int j = M - 1; j >= 0; j--) 
             {
               printf("%d ", a[i][j]);
             }
           printf("\n");
        }

    return 0;
}