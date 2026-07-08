#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/**
 * This guessing game has been adopted from: https://blog.root-me.org/posts/writeup_snippet_05/
 * <p>
 * This challenge, authored by @baguette, involves exploiting an integer overflow vulnerability combined with a stack overflow, allowing arbitrary writes to the stack.
 * <p>
 * This simplified version of the challenge focuses on the integer overflow aspect to illstrate how integer overflows can be exploited to manipulate program behavior.
 * Key: 667696AA0000
 */
int main() {
    srand(time(0)); // Initialize random number generator

    int secret_number = rand() % 1000000 + 1; // Secret number between 1 and 1000000
    char buf[10];
    int guess = 0;

    printf("Welcome to the guessing game!\n");
    printf("I have selected a number between 0 and 1,000,000. Can you guess it?\n");

    while (1) {
        printf("Enter the length of your guess (max 10): ");
        int len = 0;
        scanf("%d", &len);
        getchar();
        if (len < 0) len = abs(len);
        if (len > 10) len = 10;
        printf("Enter your guess: ");
        fflush(stdout);
                
        fgets(buf, 1000, stdin);

        printf("You entered: %s", buf);
        fflush(stdout);
        guess = atoi(buf);
        printf("You guessed: %d\n", guess);
        fflush(stdout);
        if (guess < 0 || guess > 1000000) {
            printf("Please enter a number between 1 and 1,000,000.\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the correct number.\n");
            break;
        }
    }

    return 0;
}
