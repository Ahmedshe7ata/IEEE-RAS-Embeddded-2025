#include <stdio.h>

void swap(int *num_1, int *num_2)
{
    int nan;
    nan = *num_1;
    *num_1 = *num_2;
    *num_2 = nan;


}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  swap(&a, &b);

  printf("a = %d\n", a);
  printf("b = %d", b);

return 0;
  
}