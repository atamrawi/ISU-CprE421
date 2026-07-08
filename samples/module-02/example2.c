#include <stdio.h>
#include <limits.h>
#include <assert.h>
int main(void) {
    assert(sizeof(short) == 2);
    unsigned short us = 0;
             short ss = SHRT_MIN; // -32768
    
    us -= 1;
    ss -= 1;

    printf("us(%%u)=%u\tss(%%d)=%d\n", us, ss);
    return 0;
}