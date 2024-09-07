#include <stdio.h>
#include <limits.h>
#include <assert.h>
int main(void) {
	assert(sizeof(short)==2);
	short ss = SHRT_MIN;
	int si = ss;
	printf("ss(%%hd)=%hd\tsi(%%d)=%d\n", ss, si);
	printf("ss(%%hx)=%hx\tsi(%%x)=%x\n", ss, si);
	return 0;
}

