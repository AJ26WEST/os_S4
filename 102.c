#include <stdio.h>
int main() {
    int i, j, min, rs[25], m[10], count[10], n, f, pf = 0, next = 1;
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    printf("Enter the page references: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        m[i] = -1;
        count[i] = 0;
    }
    printf("\nLRU Page Replacement\n");
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                count[j] = next++;
                break;
            }
        }
        if (!found) {
            if (i < f) {
                m[i] = rs[i];
                count[i] = next++;
            } else {
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j]) {
                        min = j;
                    }
                }
                m[min] = rs[i];
                count[min] = next++;
            }
            pf++;
        }
        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }
        if (!found)
            printf("PF No. %d", pf);
        printf("\n");
    }
    printf("\nTotal number of page faults using LRU: %d\n", pf);
    return 0;
}
