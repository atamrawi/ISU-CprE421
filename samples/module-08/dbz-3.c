#include <stdbool.h>
#include <stdio.h>

int computeX(int a1, int a2, bool C1) {
    if (C1) {
        return a1;
    }
    return a1 + a2;
}

int computeD(int a1, int a2, bool C2, bool C3) {
    int d = a1;
    if (C2) {
        if (C3) {
            int y = a1;
        } else {
            d = d - a1;
        }
    } else {
        d = d + 1;
    }
    return d;
}

int performOperation(int x, int d, bool C1, bool C2, bool C3) {
    if (C1) {
        return x;
    }

    if (C2) {
        if (C3) {
            int z = x / d;
            return z;
        }
    }

    return x + 1;
}

void main(int a1, int a2, bool C1, bool C2, bool C3) {
    int x = computeX(a1, a2, C1);
    int d = computeD(a1, a2, C2, C3);
    int result = performOperation(x, d, C1, C2, C3);
    printf("Result %d\n", result);
}
