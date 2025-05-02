#include <stdio.h>

typedef struct {
    char name[10];   // 10 bytes
    int age;         // 4 bytes
    char kind;       // 1 byte
} Animal;

int main() {
    Animal myPet;

    printf("Size of Animal struct: %lu bytes\n", sizeof(myPet));

    return 0;
}
