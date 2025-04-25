#include <stdio.h>

int main()
{
    char *name_1;
    char *name_2;
    int i=0, k=0;
    int value = 1;
    
    printf("enter string 1:");
    fgets(name_1, 100, stdin);
    
    printf("enter string 2:");
    fgets(name_2, 100, stdin);
    
    while(name_1[i] != '\0' || name_2[k] != '\0')
    {
        if(name_1[i] != name_2[k])
        {
          value = 0;
          break;
        }
        
        i++;
        k++;
        
    }
    
    if(value)
    {
        printf("Both strings are Identical");
    }
    else{
        printf("Both strings are not Identical");
    }
    
    

    return 0;
}