#include <stdio.h>
int main() {
    int avail[10], alloc[10][10], max[10][10], need[10][10], maxres[10];
    int finish[10], safeseq[10];
    int m, n, i, j, k, sum, ind = 0, executed_processes = 0;
    printf("\nEnter the number of processes and the number of resources: ");
    scanf("%d%d", &n, &m);
    printf("\nEnter maximum instances of resources: \n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        avail[j] = maxres[j];
    }
    printf("\nEnter the Allocated Matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nEnter the Max Matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\nThe Need Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < m; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += alloc[i][j];
        }
        avail[j] -= sum;
    }
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    int flag = 1;
    while (executed_processes < n && flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canExecute = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute) {
                    safeseq[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    executed_processes++;
                    flag = 1;
                }
            }
        }
    }
    if (executed_processes < n) {
        printf("\n System is in an unsafe state. Deadlock may occur.\n");
        return 0;
    }
    printf("\nFollowing is the SAFE Sequence:\n");
    for (i = 0; i < n - 1; i++) {
        printf(" P%d ->", safeseq[i]);
    }
    printf(" P%d\n", safeseq[n - 1]);
    return 0;
}
