#include <stdio.h>

int main() {
    char str[1000005]; 
    fgets(str, sizeof(str), stdin);

    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (inWord == 0) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    printf("%d\n", count);
    return 0;
}
