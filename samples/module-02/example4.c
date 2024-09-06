#include <stdio.h>
#include <limits.h>
#include <assert.h>
int main(void) {
	assert(sizeof(short)==2);
	short ss = SHRT_MIN;
	unsigned int si = ss;
    printf("ss(\%d)=%d\tsi(\%d)=%u\n", ss, si);
    printf("ss(\%x)=%x\tsi(\%x)=%x\n", ss, si);
	return 0;
}