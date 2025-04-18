#include <stdio.h>
int main() {
    int days, months, years;
    printf ("enter number of days :");
    scanf ("%d", &days);
    years = days / 360;
    days %= 360;
    
    months = days / 30;
    days %= 30;
    
    printf ("years =%d years \n", years);
    printf ("months =%d months \n", months);
    printf ("days =%d days", days);
}   
    