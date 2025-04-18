#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    char S[100005];
    scanf("%s", S); 

    int count = 1; 
    for (int i = 1; i < N; i++) {
        if (S[i] != S[i - 1]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
