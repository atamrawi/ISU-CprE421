#include <stdio.h>
void printMsg(FILE* file, char* msg) {
	if(file == NULL) {
		printf("%s", "File is NULL\n");
	} else if(msg == NULL) {
		printf("%s", "Message is NULL\n");
	} else {
		fprintf(file, msg);
		fflush(file);
	}
}

int main(int argc, char** argv) {
	if(argc < 3) {  // Ensure there are at least 2 arguments
		printf("Usage: %s <filename> <message>\n", argv[0]);
		return 0;
	}
	FILE *file = fopen(argv[1], "w");
	if(file == NULL) {
		printf("Failed to open file %s\n", argv[1]);
		return 1;
	}
	char* msg = argv[2];
	printMsg(file, msg);
	fclose(file);
	return 0;
}