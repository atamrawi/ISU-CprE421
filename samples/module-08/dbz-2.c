#include <stdbool.h>

void foo(int a1, int a2, int y, bool C1, bool C2, bool C3) {
    int x = a1 + a2;
    int d = a1;
    if (C1) {
        x = a1;
    } else {
        x = a2 - 1;
    }

    if (C2) {
        if (C3) {
            y = a1;
        } else {
            d = d - a1;
        }
    } else {
        d = d + 1;
    }
    int z = x / d;
}

void main() {
    foo(10, 20, 30, true, true, true);
}
