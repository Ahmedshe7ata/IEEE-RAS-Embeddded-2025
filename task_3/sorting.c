#include <stdio.h>
 
int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        int minidx = i;
        
        for(int j = i +1; j < n; j++)
        {
          if(arr[j] < arr[minidx])
          {
            minidx = j;  
          } 
          
            
        }
        if (minidx != i) {
    int temp = arr[i];
    arr[i] = arr[minidx];
    arr[minidx] = temp;
}
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
 
     return 0;
}