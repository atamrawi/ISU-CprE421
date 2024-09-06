#include <stdio.h>
#include <limits.h>
#include <assert.h>
#define MAGIC_NUMBER 0xFFFF7F8F
int main(void) {
	assert(sizeof(short)==2);
	unsigned int ui = MAGIC_NUMBER;
	unsigned short us = ui;
	unsigned char uc = us;
	int si = MAGIC_NUMBER;
	short ss = si;
	signed char sc = ss;
	printf("%10u %5hu %4hhu\n", ui, us, uc);
	printf("%10x %5hx %4hhx\n", ui, us, uc);
	printf("%10d %5hd %4hhd\n", si, ss, sc);
	printf("%10x %5hx %4hhx\n", si, ss, sc);
	return 0;
}
