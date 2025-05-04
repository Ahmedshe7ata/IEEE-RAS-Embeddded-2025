#include <stdio.h>

union Data {
    int a;
    float b;
    char c;
};

void print_all(union Data d) {
    printf("a (int)   = %d\n", d.a);
    printf("b (float) = %f\n", d.b);
    printf("c (char)  = %c\n", d.c);
    printf("------------------------\n");
}

int main() {
    union Data d;

    
    d.a = 65;
    printf("After assigning a = 65:\n");
    print_all(d);

    
    d.b = 3.14;
    printf("After assigning b = 3.14:\n");
    print_all(d);

    
    d.c = 'Z';
    printf("After assigning c = 'Z':\n");
    print_all(d);

    return 0;
}
