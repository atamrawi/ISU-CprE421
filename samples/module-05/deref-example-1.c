#include <stdio.h>

int main() {
    int *ptr = NULL;  // Initialize a pointer to NULL

    // Attempt to dereference the null pointer
    *ptr = 42;

    printf("Value at ptr: %d\n", *ptr);
    return 0;
}
