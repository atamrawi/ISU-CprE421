#include <stdio.h>
#include <limits.h>
#include <assert.h>
int main(void) {
	assert(sizeof(short)==2);
	short ss = SHRT_MIN;
	int si = ss;
	printf("%d %d\n", ss, si);
	printf("%x %x\n", ss, si);
	return 0;
}