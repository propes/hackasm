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

void writeStringToFile(char *filename, char *out) {
}

void stripWhiteSpace(char *str, char *out) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            out[j] = str[i];
            j++;
        }
    }
    for (; j < sizeof(out); j++) {
        out[j] = '\0';
    }
}

void stripComments(char *str, char *out) {
    int j = 0;
    int copy = 1;
    int len = strlen(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '\\') {
            copy = 0;
        }
        else if (str[i] == '\n') {
            copy = 1;
        }

        if (copy > 0) {
            out[j] = str[i];
            j++;
        }
    }
    for (; j < sizeof(out); j++) {
        out[j] = '\0';
    }
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
    stripWhiteSpace(field1, field1w);
    stripWhiteSpace(field2, field2w);

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

int preprocessAssemblyLine(char *str, char *out, int *line, SYMBOL_TABLE *table) {
    size_t len = strlen(str);
    char noComments[len];
    char clean[len];
    stripComments(str, noComments);
    stripWhiteSpace(noComments, clean);

    // If line is blank for newline
        // return

    // If contains label
        // Add label to symbol table
        // return

    strcat(out, clean);

    line++;

    return 0;
}

int parseAssemblyFile(char *filename, char *outString, SYMBOL_TABLE *table) {
    FILE *fptr;
    if ((fptr = fopen(filename, "r")) == NULL) {
        #ifdef MESSAGES_ON
            printf("Error opening file: '%s'.\n", filename);
        #endif
        return -1;
    }

    char str[100];
    int fileSize = getFileSize(filename);
    char buffer[fileSize];

    // First pass
    int line = 1;
    while (fgets(str, 100, fptr) != NULL) {
        preprocessAssemblyLine(str, buffer, &line, table);
    }

    // Second pass
    rewind(fptr);
    while (fgets(str, 100, fptr) != NULL) {
    }

    fclose(fptr);

    return 0;
}