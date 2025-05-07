#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *ptr = (int *)malloc(2 * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not available (malloc).\n");
        exit(1);
    }

    printf("Enter two numbers (for malloc):\n");
    for (i = 0; i < 2; i++)
    {
        scanf("%d", ptr + i);
    }

    for (i = 0; i < 2; i++)
    {
        printf("From malloc: %d\n", *(ptr + i));
    }

    
    free(ptr);
    ptr = (int *)malloc(6 * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not available (new malloc after free).\n");
        exit(1);
    }

    printf("Enter six numbers (for bigger malloc):\n");
    for (i = 0; i < 6; i++)
    {
        scanf("%d", ptr + i);
    }

    for (i = 0; i < 6; i++)
    {
        printf("From bigger malloc: %d\n", *(ptr + i));
    }

    
    int *ptr2 = (int *)calloc(3, sizeof(int));
    if (ptr2 == NULL)
    {
        printf("Memory not available (calloc).\n");
        exit(1);
    }

    printf("Enter three numbers (for calloc):\n");
    for (i = 0; i < 3; i++)
    {
        scanf("%d", ptr2 + i);
    }

    for (i = 0; i < 3; i++)
    {
        printf("From calloc: %d\n", *(ptr2 + i));
    }

    free(ptr);
    free(ptr2);

    

    return 0;
}
