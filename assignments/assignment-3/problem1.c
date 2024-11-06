#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void vuln(char *string) {
    volatile int target;
    char buffer[16];
    target = 0;
    
    sprintf(buffer, string);
    
    if(target == 0xdeadbeef) {
        printf("You've got a reward :)\n");
    } else {
        printf("Target = %p", target);
    }
}

int main(int argc, char **argv) {
    vuln(argv[1]);
}