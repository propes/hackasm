#include <stdio.h>
#include <string.h>

char * openFileIntoString(char * filename) {
}

void writeStringToFile(char * out) {
}

void stripWhiteSpace(char * str, char * out) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        out[j] = str[i];
        j++;
    }
    out[j] = '\0';
}

char * stripComments(char * str) {
}

char * addLabelsToSymbolTable(char * str, char * symbols[][2]) {
}

char ** parseAssemblyString(char * str, char * symbols[][2]) {
    char nowhitespace[strlen(str)];
    stripWhiteSpace(str, nowhitespace);
    str = stripComments(str);

    addLabelsToSymbolTable(str, symbols);

    // Second pass: go through the array
        // Add variables to the symbol table
        // Replace symbols with values
        // Translate instruction to machine language
}

char * concatenateArray(char * instructions[]) {
}

char * convertAssemblyToMachine(char * str, char * out, char * symbols[][2]) {
    char ** instructions = parseAssemblyString(str, symbols);

    return concatenateArray(instructions);
}