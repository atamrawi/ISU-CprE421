#include <stdio.h>
int main(void) {
    unsigned short a = 65000;
    unsigned short b = 540;
    unsigned short c = 0;
    c = a + b;
    printf("Result is %u + %u = %u\n", a, b, c);
    return 0;
}