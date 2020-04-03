#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
    char *name;
    int value;
} SYMBOL;

size_t getFileSize(char *filename) {
    // https://wiki.sei.cmu.edu/confluence/display/c/FIO19-C.+Do+not+use+fseek()+and+ftell()+to+compute+the+size+of+a+regular+file

    char *buffer;
    struct stat stbuf;
    int fd;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        /* Handle error */
    }
    
    if ((fstat(fd, &stbuf) != 0) || (!S_ISREG(stbuf.st_mode))) {
        /* Handle error */
    }
    
    return stbuf.st_size;
}

void readFileIntoString(char *filename, char *str) {
    FILE *fptr;
    fptr = fopen(filename, "r");

    fscanf(fptr,"%s", str);

    fclose(fptr);
}

void writeStringToFile(char *filename, char *out) {
}

void stripWhiteSpace(char *str, char *out) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        out[j] = str[i];
        j++;
    }
    out[j] = '\0';
}

char * stripComments(char *str) {
}

char * addLabelsToSymbolTable(char *str, char *symbols[][2]) {
}

char ** parseAssemblyString(char *str, char *symbols[][2]) {
    char nowhitespace[strlen(str)];
    stripWhiteSpace(str, nowhitespace);
    str = stripComments(str);

    addLabelsToSymbolTable(str, symbols);

    // Second pass: go through the array
        // Add variables to the symbol table
        // Replace symbols with values
        // Translate instruction to machine language
}

void convertAssemblyToMachineCode(char *str, char *out, SYMBOL *symbols) {
    // Read each character until next line break
    // and copy each character into a buffer string.

    // Parse the assembly string
}

void readSymbolsFromFile(char *filename, SYMBOL *symbols) {

}