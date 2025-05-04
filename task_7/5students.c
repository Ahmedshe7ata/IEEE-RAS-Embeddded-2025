#include <stdio.h>

typedef struct {
    unsigned int roll_number : 4;
    unsigned int age : 8;
    unsigned int marks : 3;
    char name[100];
    char address[100];
} data;

void student_info(data students[], int size);
void print_data(data students[], int size);

int main() {
    data students[5];
    student_info(students, 5);
    print_data(students, 5);
    return 0;
};

void student_info(data students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%u", &students[i].roll_number);

        printf("Age: ");
        scanf("%u", &students[i].age);

        printf("Marks (0-7): ");
        scanf("%u", &students[i].marks);
        getchar(); // to clear newline

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Address: ");
        fgets(students[i].address, sizeof(students[i].address), stdin);
    }
};

void print_data(data students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nStudent %d Info:\n", i + 1);
        printf("Roll Number: %u\n", students[i].roll_number);
        printf("Age: %u\n", students[i].age);
        printf("Marks: %u\n", students[i].marks);
        printf("Name: %s", students[i].name);
        printf("Address: %s", students[i].address);
    }
};
