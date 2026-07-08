#include <stdio.h>
#include <limits.h>
#include <assert.h>
int main(void) {
	assert(sizeof(short)==2);
	unsigned short us = 0x8080;
	short ss = us;
	printf("%6hu %6hd\n", us, ss);
	printf("%6hx %6hx\n", us, ss);
	return 0;
}