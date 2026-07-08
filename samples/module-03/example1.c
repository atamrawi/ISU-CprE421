#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int passCheck = 0;
    char password[16];
    printf("Enter password: ");
    scanf("%s", password);
    
    if (strcmp(password, "secret")) {
        printf("\nWrong Password!\n");
    } else {
        printf("\nCorrect Password\n");
        passCheck = 1;
    }
    
    if (passCheck) {
        system("cat /etc/shadow");
    }
    
    return 0;
}