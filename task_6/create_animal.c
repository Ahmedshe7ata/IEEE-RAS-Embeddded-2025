#include <stdio.h>
#include <string.h>


typedef struct {
    char name[50];
    int age;
    char kind[50];
} Animal;


Animal create_animal(char name[], int age, char kind[]) {
    Animal a;
    strcpy(a.name, name);
    a.age = age;
    strcpy(a.kind, kind);
    return a;
}


void print_animal(Animal a) {
    printf("Animal Details:\n");
    printf("Name: %s", a.name);
    printf("Age: %d\n", a.age);
    printf("Kind: %s", a.kind);
}

int main() {
    char name[50], kind[50];
    int age;

    printf("Enter animal name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter animal age: ");
    scanf("%d", &age);
    getchar(); 

    printf("Enter animal kind (Dog/Cat): ");
    fgets(kind, sizeof(kind), stdin);

    Animal pet = create_animal(name, age, kind);
    print_animal(pet);

    return 0;
}
