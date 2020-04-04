#include <stdio.h>
#include <stdlib.h>
#include "hackAssemblerLib.h"

int main(int argc, char *argv[]) {

    char *filename = argv[0];

    SYMBOL_TABLE table;
    readSymbolsFromFile("symbols.csv", &table);

    size_t fs = getFileSize(filename);
    char fileString[fs];

    // TODO: this needs to change. Can only read one line at a time.
    readFileIntoString(filename, fileString);

    char *outString = (char *) malloc(fs * sizeof(char));

    convertAssemblyToMachineCode(fileString, outString, &table);

    writeStringToFile("out.hack", outString);

    free(outString);
}