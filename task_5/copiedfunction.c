#include<stdio.h>

void copy(char * stri)
{
   printf("copied string: %s", stri);
 
}

int main() 
{  
    char str[1000];
    fgets(str, sizeof(str), stdin);
   
    printf("original string: %s\n", str);
    void (*ptr)(char*);
    ptr = copy;
    ptr(str);
   
return 0;
}