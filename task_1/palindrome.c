#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int len;
    int i;
    printf("enter the word :");
    scanf("%s", word);
    
    len = strlen(word);
    
    for (i = 0; i < len / 2; i++)
    {
       if (word[i] != word[len - i - 1])
         {
            printf("the word '%s' is  not a palindrome", word);
            break;
         }
       else
         {
            printf("the word '%s' is a palindrome", word);
            break;
         } 
    }
    
   
    return 0;
}