#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * This guessing game has been adopted from: https://systemweakness.com/integer-overflow-simplesums-writeup-0e4b6dcf35d0 based on MetaCTF challenge.
 * <p>
 * This challenge, authored by @baguette, involves exploiting an integer overflow vulnerability.
 */
int main() {

  // Intro text
  printf("Welcome to the SimpleSum calculator!\n\n");
  printf("Provide two integers between 0 and %d, inclusive\n\n", INT_MAX); //INT_MAX is 2147483647

  // Get the first integer from user
  int a;
  printf("Enter the first positive integer: ");
  if(scanf("%d", &a) != 1 || a <= 0) {
    printf("Invalid input. Exiting.\n");
    return 1;
  }

  // Get the second integer from user
  int b;
  printf("Enter the second positive integer: ");
  if(scanf("%d", &b) != 1 || b <= 0) {
    printf("Invalid input. Exiting.\n");
    return 1;
  }

  // Add the two integers a and b and print the resulting sum to the user
  int sum = a + b;
  printf("\nThe sum is %u\n\n", sum);

  // Check if the sum equals -1337 and give the flag if it does
  if (sum == -1337) {
    printf("Good job! Here's your flag: MetaCTF{counting_beyond_infinity}\n");
  } else {
    printf("No flag for you! Exiting.\n");
  }
  
  return 0;
}