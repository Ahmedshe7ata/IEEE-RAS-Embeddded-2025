#include <stdio.h>
#include <string.h>
int main()
{
    struct type
    {
        char name[30];
        int age;
        char kind[30];
        char food[30];
        char owner_name[30];
        
        
    };
    
    struct type ty1,ty2;
    
    strcpy(ty1.name,"dog");
    ty1.age = 4;
    strcpy(ty1.kind,"male");
    strcpy(ty1.food,"meat");
    strcpy(ty1.owner_name,"ahmed");
    
    printf("dog details :\n");
    printf("age = %d\n", ty1.age);
    printf("name :%s\n", ty1.name);
    printf("name :%s\n", ty1.kind);
    printf("name :%s\n", ty1.food);
    printf("name :%s\n", ty1.owner_name);
    
    strcpy(ty2.name,"cat");
    ty2.age = 4;
    strcpy(ty2.kind,"famale");
    strcpy(ty2.food,"snacks");
    strcpy(ty2.owner_name,"doda");
    
    printf("\n");
    printf("cat details :\n");
    printf("age = %d\n", ty2.age);
    printf("name :%s\n", ty2.name);
    printf("name :%s\n", ty2.kind);
    printf("name :%s\n", ty2.food);
    printf("name :%s\n", ty2.owner_name);
    

    return 0;
}