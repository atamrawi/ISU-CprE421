#include <stdio.h>

int main() {
    int n;

    // Prompt user to enter a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Loop until n is greater than 1
    while (n > 1) {
        if (n % 2 == 0) {
            // If n is even, divide it by two
            n = n / 2;
        } else {
            // If n is odd, multiply by three and add one
            n = 3 * n + 1;
        }
        // Print the current value of n
        printf("%d\n", n);
    }

    return 0;
}
