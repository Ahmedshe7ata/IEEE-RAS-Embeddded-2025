#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, sum=0;
    printf("enter number of intgers:");
    scanf("%d", &n);

    int *arr =(int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not available (malloc).\n");
        exit(1);
    }
    printf("enter %d integrs:", n);

    for(i=0; i<n; i++)
    {
       scanf("%d", &arr[i]);
       sum += arr[i];
    }

    printf("sum of intgers :%d", sum);
    free(arr);

    return 0;


}
