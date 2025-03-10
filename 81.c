#include <stdio.h>
#define max 25
int main() {
int frag[max], b[max], f[max], i, j, nb, nf, temp;
static int bf[max], ff[max]; // bf: block flag, ff: file allocation block
printf("\n\tMemory Management Scheme - First Fit");
printf("\nEnter the number of blocks:");
scanf("%d", &nb); // Read the number of memory blocks
printf("Enter the number of files:");
scanf("%d", &nf); // Read the number of files to allocate
printf("\nEnter the size of the blocks:-\n");
for (i = 1; i <= nb; i++) {
printf("Block %d:", i);
scanf("%d", &b[i]); // Read the size of each memory block
}
printf("Enter the size of the files :-\n");
for (i = 1; i <= nf; i++) {
printf("File %d:", i);
scanf("%d", &f[i]); // Read the size of each file
}
// First Fit Allocation Logic
for (i = 1; i <= nf; i++) { // Iterate through each file
ff[i] = 0; // Initialize ff[i] to 0, indicating no block allocated yet
frag[i] = 0; // Initialize fragment size to 0
for (j = 1; j <= nb; j++) { // Iterate through each memory block
if (bf[j] != 1) { // Check if the block is not already allocated
temp = b[j] - f[i]; // Calculate the remaining space if file i is allocated to block j
if (temp >= 0) { // Check if the block has enough space for the file
ff[i] = j; // Allocate file i to block j
frag[i] = temp; // Store the fragmentation size
bf[j] = 1; // Mark block j as allocated
break; // Exit the inner loop since a suitable block is found
}
}
}
}
// Print the allocation results
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
for (i = 1; i <= nf; i++) {
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d ", i, f[i], ff[i], b[ff[i]], frag[i]);
}
return 0;
}
