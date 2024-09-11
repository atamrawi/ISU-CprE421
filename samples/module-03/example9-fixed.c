#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned int connections = 0;
    // Insert network code here
    // ...
    // Prevents overflow conditions
    if (connections < 5) {
        connections++;
    }
    
    if (connections < 5) {
        grant_access();
    } else {
        deny_access();
    }
    
    return 1;
}