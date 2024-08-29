#include <stdio.h>
void printMsg(FILE* file, char* msg) {
	fprintf(file, msg);
    fflush(file);
}

int main(int argc, char** argv) {
	FILE *file = fopen(argv[1], "w");
	char* msg = argv[2];
	printMsg(file, msg);
	fclose(file);
	return 0;
}