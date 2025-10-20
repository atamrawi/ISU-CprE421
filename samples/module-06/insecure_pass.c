// insecure_string_compare.c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Insecure string compare function (vulnerable to timing attacks)
bool insecure_string_compare(const char *a, const char *b) {
    size_t la = strlen(a);
    size_t lb = strlen(b);

    // Ensure both strings are of the same length
    if (la != lb) {
        return false;
    }

    // Compare character by character
    for (size_t i = 0; i < la; ++i) {
        // Print each comparison (this I/O dominates timing)
        printf("Comparing '%c' with '%c'\n", a[i], b[i]);
        if (a[i] != b[i]) {
            return false; // early return: timing vulnerability
        }
    }

    return true; // Strings are equal
}

long long timespec_to_ns(const struct timespec *ts) {
    return (long long)ts->tv_sec * 1000000000LL + ts->tv_nsec;
}

int main(void) {
    const char *str1 = "SuperSecretPassword";
    const char *str2 = "ScperSecretPassworx"; // Intentional mismatch at the end

    // Measure start time
    struct timespec tstart, tend;
    if (clock_gettime(CLOCK_MONOTONIC, &tstart) != 0) {
        perror("clock_gettime");
        return 1;
    }

    // Call the insecure string compare function
    bool result = insecure_string_compare(str1, str2);

    // Measure end time
    if (clock_gettime(CLOCK_MONOTONIC, &tend) != 0) {
        perror("clock_gettime");
        return 1;
    }

    long long start_ns = timespec_to_ns(&tstart);
    long long end_ns   = timespec_to_ns(&tend);
    long long duration = end_ns - start_ns;

    printf("Strings are equal: %s\n", result ? "true" : "false");
    printf("Time taken (milli-seconds): %lld\n", duration);

    return 0;
}
