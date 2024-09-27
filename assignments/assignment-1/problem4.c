#include <stdio.h>
#include <string.h>

#define MAX_BUF_SZ 40  // Define the constant as a macro

int main() {
    int charsCount;
    char inputBuffer[MAX_BUF_SZ];  // Buffer to hold input string
    char dstBuffer[MAX_BUF_SZ];    // Destination buffer to copy the string

    printf("Enter the number of characters to enter: ");
    scanf("%d", &charsCount);

    // Make sure charsCount is within the valid buffer size
    if (charsCount > MAX_BUF_SZ) {
        printf("Error: Cannot enter more than %d characters!\n", MAX_BUF_SZ);
        return -1;
    }

    printf("Enter your string: ");
    // Using scanf to read input
    scanf("%s", inputBuffer);  // Be cautious: this reads until a space or newline.

    // Use strncpy to copy the input buffer into destination buffer
    strncpy(dstBuffer, inputBuffer, charsCount);

    printf("Copied string: %s\n", dstBuffer);

    return 0;
}
