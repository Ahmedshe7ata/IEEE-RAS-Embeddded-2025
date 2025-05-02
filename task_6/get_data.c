#include <stdio.h>

typedef struct xx 
{
  int salary;
  char name[100];
       
} Handas;
   
   

Handas get_data(void);
void print_data(Handas H);

 
int main()
{
    
   Handas H1;
   H1 = get_data();
   print_data(H1);


    return 0;
};

Handas get_data(void)
{
   Handas H;
   
   printf("your salary:\n");
   scanf("%d",&H.salary);
   getchar();
   printf("your name:\n");
   fgets(H.name, sizeof(H.name), stdin);
   return(H);

   
};

void print_data(Handas H)
{
    printf("salary : %d\n", H.salary);
    printf("name : %s\n", H.name);
};