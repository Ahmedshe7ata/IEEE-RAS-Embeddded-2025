#include <stdio.h>

int main() {
    int n, i, j;
    int *ptr1;
    ptr1 = &n;

    scanf("%d", ptr1);
    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    for (i = 0; i < n - 1; i++) {
        int minidx = i;
        for (j = i + 1; j < n; j++) {
            if (*(a + j) < *(a + minidx)) {
                minidx = j;
            }
        }

        if (minidx != i) {
            int temp = *(a + i);
            *(a + i) = *(a + minidx);
            *(a + minidx) = temp;
        }
    }
        printf("Array in ascending order:");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    
    for (i = 0; i < n - 1; i++) {
        int maxidx = i;
        for (j = i + 1; j < n; j++) {
            if (*(a + j) > *(a + maxidx)) {
                maxidx = j;
            }
        }

        if (maxidx != i) {
            int temp = *(a + i);
            *(a + i) = *(a + maxidx);
            *(a + maxidx) = temp;
        }
    }
    printf("\n");
    printf("Array in descending order:");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }

    return 0;
}