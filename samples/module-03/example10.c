#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main() {
    int numToAllocate;

    printf("Enter the number of integers to allocate: ");
    scanf("%d", &numToAllocate);

    // Check if the requested allocation size is valid
    if (numToAllocate > MAX_SIZE) {
        printf("Error: Cannot allocate more than %d integers!\n", MAX_SIZE);
        return -1;
    }

    // Calculate and print the number of bytes to be allocated
    size_t bytesToAllocate = numToAllocate * sizeof(int);
    printf("Allocating %zu bytes of memory.\n", bytesToAllocate);

    // Allocate memory for the buffer (risk of integer overflow here)
    int* buffer = (int*)malloc(bytesToAllocate);

    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    // Use the allocated buffer
    
    // Free the allocated memory (cleanup)
    free(buffer);

    return 0;
}


