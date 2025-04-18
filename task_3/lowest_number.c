#include <stdio.h>
 
int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int min = arr[0], x = 1;
    
    
    for(i=0; i<n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            x = i + 1; 
        }
         
    }
      
     printf("%d %d", min, x);
     return 0;
}