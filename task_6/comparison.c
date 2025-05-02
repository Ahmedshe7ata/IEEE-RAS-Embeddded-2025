#include <stdio.h>

typedef struct {
    int day;
    char a[100];  
    int month;
    char b[100];  
    int year;
} Date;


Date get_data() {
    Date d;

    printf("Enter day: ");
    scanf("%d", &d.day);
    getchar();

    printf("Enter day name: ");
    fgets(d.a, sizeof(d.a), stdin);

    printf("Enter month number: ");
    scanf("%d", &d.month);
    getchar();

    printf("Enter month name: ");
    fgets(d.b, sizeof(d.b), stdin);

    printf("Enter year: ");
    scanf("%d", &d.year);

    return d;
}

int compare_strings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return 0; 
        i++;
    }
}
   

void comparison(Date *a, Date *b) {
    if (a->day == b->day &&
        a->month == b->month &&
        a->year == b->year &&
        compare_strings(a->a, b->a) &&
        compare_strings(a->b, b->b)) {
        printf("Dates are equal.\n");
    } else {
        printf("Dates are not equal.\n");
    }
}

int main() {
    Date date1, date2;

    printf("Enter first date:\n");
    date1 = get_data();

    printf("\nEnter second date:\n");
    date2 = get_data();

    printf("\nComparison result:\n");
    comparison(&date1, &date2);

    return 0;
}
