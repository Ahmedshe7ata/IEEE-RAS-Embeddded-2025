#include <stdio.h>
#include <string.h>



void lenght(char* n)
{
    printf("lenght = %ld", strlen(n));
}



int main()
{
    char str[]="Embedded Systems";
    int len = strlen(str);
    void(*ptr)(char*);
    ptr = lenght;
    ptr(str);
    return 0;
}