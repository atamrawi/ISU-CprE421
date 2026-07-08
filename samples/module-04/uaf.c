#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
    char *pointer = NULL;
    int abort = 0;
    pointer = (char *) malloc(sizeof(char) * 100);
    printf("Please enter a sentence (up to 100 characters): ");
    fgets(pointer, 100, stdin);
    if(pointer != NULL) {
        abort = 1;
        free(pointer);
        printf("Memory at [%p] has been freed!\n", &pointer);
    }
    if(abort) {
        printf("&pointer= %p\n", (void*)&pointer);
        strcpy(pointer, "Hello There!");
        printf("*pointer= %s\n", pointer);
        printf("&pointer= %p\n", (void*)&pointer);
    }
}
