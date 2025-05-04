#include <stdio.h>

enum Day {
    friday,     // 0
    saturday,   // 1
    sunday,     // 2
    monday,     // 3
    tuesday,    // 4
    wednesday,  // 5
    thursday    // 6
};


void print_d(enum Day d);

int main() {
    int input;
    printf("Enter day number (0 = Friday, 1 = Saturday, ..., 6 = Thursday): ");
    scanf("%d", &input);



    enum Day d1 = input;
    print_d(d1);

    return 0;
}


void print_d(enum Day d) {
    if (d == friday || d == saturday) {
        printf("It is a weekend.\n");
    } else {
        printf("It is a weekday.\n");
    }
}
