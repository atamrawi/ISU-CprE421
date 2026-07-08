#include <stdlib.h>
#include <stdio.h>
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
        pointer = NULL;
    }
    if(abort) {
        printf("&pointer= %p\n", &pointer[0]);
        printf("*pointer= %s\n", pointer);
    }
}
