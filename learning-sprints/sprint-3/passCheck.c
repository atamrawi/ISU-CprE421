#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Define the correct key for comparison
const char *correct_key = "password123";
char key_input[100];

// Function to compare the key
int compare_key() {
    unsigned int len = strlen(key_input);
    unsigned int correct_len = strlen(correct_key);
    int i, wait_time = 0, random_time, diff;

    if (len != correct_len)
        return 1;

    int diffCount = 0;
    for (i = 0; i < correct_len; i++) {
        if (key_input[i] != correct_key[i]) {
            diff = key_input[i] - correct_key[i];
            if (diff != 0) {
                diffCount++;
            }
        }
    }
    printf("Sleeping for: %d seconds\n", diffCount);

    return diffCount;
}

// Driver function
int main() {
    printf("Enter the key: ");
    fgets(key_input, sizeof(key_input), stdin);
    
    // Remove newline character if present
    size_t len = strlen(key_input);
    if (len > 0 && key_input[len - 1] == '\n') {
        key_input[len - 1] = '\0';
    }

    if (compare_key() == 0) {
        printf("Access granted!\n");
    } else {
        printf("Access denied!\n");
    }

    return 0;
}
