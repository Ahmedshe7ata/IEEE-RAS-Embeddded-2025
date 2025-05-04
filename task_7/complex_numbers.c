#include <stdio.h>


typedef struct {
    float real;
    float imag;
} Complex;


void printComplex(Complex c1, Complex c2) {
    float a, b;
    a = c1.real + c2.real;
    b = c1.imag + c2.imag;
    
    printf("sum: %.2f + %.2fi\n", a, b);
}

int main() {
    Complex c1, c2;


    printf("Enter real part1: ");
    scanf("%f", &c1.real);
    
    
    printf("Enter imaginary part1: ");
    scanf("%f", &c1.imag);
    
    printf("Enter real part2: ");
    scanf("%f", &c2.real);
    
    printf("Enter imaginary part2: ");
    scanf("%f", &c2.imag);

    
    printComplex(c1, c2);

    return 0;
}