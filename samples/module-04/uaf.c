#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
    char *pointer = NULL;
    pointer = (char *) malloc(sizeof(char) * 100);
    if(pointer == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    printf("Please enter a sentence (up to 100 characters): ");
    fgets(pointer, 100, stdin);
    free(pointer);
    printf("Memory at [%p] has been freed!\n", &pointer);
    strcpy(pointer, "Hello There!");
    printf("*pointer= %s\n", pointer);
    printf("&pointer= %p\n", (void*)&pointer);
}
