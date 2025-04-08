#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int finish[10] = {0}, safeseq[10], count = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    printf("Enter available resources: ");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    while (count < n) {
        int safe = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int can_run = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        can_run = 0;
                        break;
                    }
                }
                if (can_run) {
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    safeseq[count++] = i;
                    finish[i] = 1;
                    safe = 1;
                }
            }
        }
        if (!safe) {
            printf("System is unsafe (deadlock may occur).\n");
            return 0;
        }
    }

    printf("System is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeseq[i]);
    printf("\n");

    return 0;
}
