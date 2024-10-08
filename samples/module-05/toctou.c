#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int is_symlink(char *file) {
    struct stat file_info;
    if (lstat(file, &file_info) != 0) {
        perror("lstat() error");
        return 1;
    } else {
        return S_ISLNK(file_info.st_mode);
    }
}

void read_config(char *file) {
    char str[101];
    FILE *pFile = fopen(file, "r");
    if (pFile != NULL) {
        fscanf(pFile, "%100s", str); /* Yes, I'm limiting my input to 100 */
        printf("%s\n\n", str);
        fclose(pFile);
    }
}

int main() {
    char *file = "config";
    puts("\tIs it a symlink?");
    if (is_symlink(file)) {
        printf("...oops! This is a symlink, quitting...");
        return 0;
    }
    puts("---CONCURRENT PROCESS STARTS---");
    system("./evil-link-maker.sh");
    puts("---CONCURRENT PROCESS ENDS---\n");
    puts("Ok, I'm back! Let's use this file now...");
    read_config(file);
    return 0;
}
