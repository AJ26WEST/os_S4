/* Worst Fit */
#include <stdio.h>
#define max 25
int main() {
int frag[max], b[max], f[max], i, j, nb, nf, temp, largest; // Added 'largest' for Worst Fit logic
static int bf[max], ff[max];
printf("\n\tMemory Management Scheme - Worst Fit");
printf("\nEnter the number of blocks:");
scanf("%d", &nb);
printf("Enter the number of files:");
scanf("%d", &nf);
printf("\nEnter the size of the blocks:-\n");
for (i = 1; i <= nb; i++) {
printf("Block %d:", i);
scanf("%d", &b[i]);
}
printf("Enter the size of the files :-\n");
for (i = 1; i <= nf; i++) {
printf("File %d:", i);
scanf("%d", &f[i]);
}
for (i = 1; i <= nf; i++) { // For each file
largest = -1; // Initialize largest fragment to -1
ff[i] = 0; // Initialize file allocation to 0
frag[i] = 0; //initialize fragment to 0
for (j = 1; j <= nb; j++) { // For each block
if (bf[j] != 1) { // If block is free
temp = b[j] - f[i]; // Calculate remaining space
if (temp >= 0) { // If block can hold the file
if (largest == -1 || temp > largest) { // Find the block with the largest remaining space
largest = temp;
ff[i] = j; // Store the block number
frag[i] = temp; //Store fragment value
}
}
}
}
if(ff[i] != 0){ // if a block was allocated
bf[ff[i]] = 1; // Mark the allocated block as used.
}
}
printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
for (i = 1; i <= nf; i++) {
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}
return 0;
}
