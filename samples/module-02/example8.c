#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>
int main(void) {
	assert(sizeof(int)==4);
	int intMin = INT_MIN;
	printf("%d %d %d\n", intMin, abs(intMin), -intMin);
	return 0;
}