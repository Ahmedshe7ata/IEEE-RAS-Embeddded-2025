#include <stdio.h>
 
int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int x, found = 0;
    scanf("%d", &x);
    
    for(i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            printf("%d", i);
            found = 1;
            break;
        }
    }
        if(!found)
        {
        printf("-1");
        }
    
     return 0;
}