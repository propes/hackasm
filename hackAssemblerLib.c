#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <regex.h>
#include "symbols.h"

//#define MESSAGES_ON

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

void trimWhiteSpace(char *str, char *out) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            out[j] = str[i];
            j++;
        }
    }
    out[j] = '\0';
}

char * stripComments(char *str) {
}

char * addLabelsToSymbolTable(char *str, char *symbols[][2]) {
}

char ** parseAssemblyString(char *str, char *symbols[][2]) {
    char nowhitespace[strlen(str)];
    trimWhiteSpace(str, nowhitespace);
    str = stripComments(str);

    addLabelsToSymbolTable(str, symbols);

    // Second pass: go through the array
        // Add variables to the symbol table
        // Replace symbols with values
        // Translate instruction to machine language
}

void convertAssemblyToMachineCode(char *str, char *out, SYMBOL_TABLE *table) {
    // Read each character until next line break
    // and copy each character into a buffer string.

    // Parse the assembly string
}

int indexOfNextChar(char *str, char c, size_t len, int startIndex) {
    int i;
    for (i = startIndex; i < len; i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int matchRegex(const char *string, char *pattern)
{
    int status;
    regex_t regex;

    if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        return 0;
    }

    status = regexec(&regex, string, (size_t) 0, NULL, 0);
    regfree(&regex);
    if (status != 0) {
        return 0;
    }

    return 1;
}

int readLineIntoSymbol(char *str, SYMBOL *symbol) {
    size_t len = strlen(str);
    if (str[len - 1] == '\n') {
        len = len - 1;
    }
    int i = indexOfNextChar(str, ',', len, 0);

    // Check line is properly formed.
    // Line must contain exactly two fields.
    if (i <= 0 || i == len - 1) {
        #ifdef MESSAGES_ON
            printf("Invalid symbol file: at least one line does not contain two fields.\n");
        #endif
        return -1;
    }

    // TODO: handle strings longer than field buffers.
    char field1[50] = "";
    char field2[50] = "";
    strncpy(field1, str, i);
    strncpy(field2, &str[i + 1], len - i - 1);

    // Remove whitespace.
    char field1w[50];
    char field2w[50];
    trimWhiteSpace(field1, field1w);
    trimWhiteSpace(field2, field2w);

    // Second field must contain only digits.
    if (matchRegex(field2w, "^[0-9]+$") == 0) {
        #ifdef MESSAGES_ON
            printf("Invalid symbol file: second field must only contain numbers.\n");
        #endif
        return -1;
    }

    // Copy fields into symbol.
    strcpy(symbol->name, field1w);
    strcpy(symbol->value, field2w);

    return 0;
}

int readSymbolsFromFile(char *filename, SYMBOL_TABLE *table) {
    FILE *fptr;
    if ((fptr = fopen(filename, "r")) == NULL) {
        #ifdef MESSAGES_ON
            printf("Error opening file: '%s'.\n", filename);
        #endif
        return -1;
    }

    int fileSize = getFileSize(filename);
    char str[fileSize];

    while (fgets(str, fileSize + 1, fptr) != NULL) {
        SYMBOL symbol;
        int err = readLineIntoSymbol(str, &symbol);

        // Handle error
        if (err < 0) {
            return -1;
        }

        addSymbol(table, symbol);
    }

    fclose(fptr);

    return 0;
}