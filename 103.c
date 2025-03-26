#include <stdio.h>
int main() {
    int rs[50], i, j, k, numRefs, f, cntr[20], min, pf = 0, found, frame[20];
    printf("\nEnter number of page references: ");
    scanf("%d", &numRefs);
    printf("\nEnter the page references: ");
    for (i = 0; i < numRefs; i++)
        scanf("%d", &rs[i]);
    printf("\nEnter the number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        cntr[i] = 0;
        frame[i] = -1;
    }
    printf("\n LFU Page Replacement \n");
    for (i = 0; i < numRefs; i++) {
        found = 0;
        for (j = 0; j < f; j++) {
            if (rs[i] == frame[j]) {
                cntr[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    frame[j] = rs[i];
                    cntr[j] = 1;
                    pf++;
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            min = 0;
            for (k = 1; k < f; k++) {
                if (cntr[k] < cntr[min])
                    min = k;
            }
            frame[min] = rs[i];
            cntr[min] = 1;
            pf++;
        }
        printf("\n");
        for (j = 0; j < f; j++)
            printf("\t%d", frame[j]);
        if (!found)
            printf("\tPF No. %d", pf);
    }
    printf("\n\nTotal number of page faults: %d\n", pf);
    return 0;
}
