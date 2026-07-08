#include <stdlib.h>
#include <stdio.h>
int main() {
    while (1) {
        void* mem = malloc(sizeof(char));
        free(mem);
    }
    return 0;
}
