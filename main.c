#include <stdio.h>
#include <stdlib.h>
#include "hackAssemblerLib.h"

int main(int argc, char *argv[]) {

    char *filename = argv[0];

    SYMBOL symbols[128];
    getPredefinedSymbolsFromFile("symbols.csv", symbols);

    size_t fs = getFileSize(filename);
    char fileString[fs];

    openFileIntoString(filename, fileString);

    char *outString = (char *) malloc(fs * sizeof(char));

    convertAssemblyToMachineCode(fileString, outString, symbols);

    writeStringToFile("out.hack", outString);

    free(outString);

    return 0;
}