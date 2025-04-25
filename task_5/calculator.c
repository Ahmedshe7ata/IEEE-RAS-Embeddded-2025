#include<stdio.h>

int add(int a, int b); 
int sub(int a, int b); 
int mul(int a, int b); 
int div(int a, int b);

int main()
{
  int num_1, num_2, opr;
  int (*calc[4])(int ,int)={add,sub,mul,div};
  int res;

  printf("Enter first number:");
  scanf("%d", &num_1);
  printf("Enter second number:");
  scanf("%d", &num_2);

  printf("choose your operation: 1-add  2-subtraction  3-multiplication  4-division");
  scanf("%d", &opr);

  res = calc[opr-1](num_1, num_2);
  printf("result = %d", res);


  return 0;
}

int add(int a, int b) { return (a+b);}
int sub(int a, int b) { return (a-b);}
int mul(int a, int b) { return (a*b);}
int div(int a, int b) { return (a/b);}
