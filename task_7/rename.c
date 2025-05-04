#include <stdio.h>


typedef int myInt;
typedef float myFloat;
typedef double myDouble;
typedef char myChar;
typedef short myShort;
typedef long myLong;
typedef long long myLongLong;
typedef unsigned int myUnsignedInt;
typedef unsigned char myUnsignedChar;
typedef unsigned short myUnsignedShort;
typedef unsigned long myUnsignedLong;
typedef unsigned long long myUnsignedLongLong;

int main() {
    printf("Size of myInt: %zu bytes\n", sizeof(myInt));
    printf("Size of myFloat: %zu bytes\n", sizeof(myFloat));
    printf("Size of myDouble: %zu bytes\n", sizeof(myDouble));
    printf("Size of myChar: %zu bytes\n", sizeof(myChar));
    printf("Size of myShort: %zu bytes\n", sizeof(myShort));
    printf("Size of myLong: %zu bytes\n", sizeof(myLong));
    printf("Size of myLongLong: %zu bytes\n", sizeof(myLongLong));
    printf("Size of myUnsignedInt: %zu bytes\n", sizeof(myUnsignedInt));
    printf("Size of myUnsignedChar: %zu bytes\n", sizeof(myUnsignedChar));
    printf("Size of myUnsignedShort: %zu bytes\n", sizeof(myUnsignedShort));
    printf("Size of myUnsignedLong: %zu bytes\n", sizeof(myUnsignedLong));
    printf("Size of myUnsignedLongLong: %zu bytes\n", sizeof(myUnsignedLongLong));
    
    return 0;
}
