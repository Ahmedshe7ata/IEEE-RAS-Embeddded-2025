#include <stdio.h>
#include <string.h>



void Even(char* n)
{
    int i;
    for(i=0; i<strlen(n); i++)
    {
        if(n[i] % 2 == 0)
        {
            printf("%c", n[i]);
        }
        
    }
}



int main()
{
    char str[]="012345678";
    int lenght = strlen(str);
    void(*ptr)(char*);
    ptr = Even;
    ptr(str);
    return 0;
}