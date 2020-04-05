#include <stdio.h>
#include <stdlib.h>
#include "hackAssemblerLib.h"

int main(int argc, char *argv[]) {

    char *filename = argv[0];

    SYMBOL_TABLE table;
    if (readSymbolsFromFile("symbols.csv", &table) < 0) {
        return 0;
    }

    size_t fs = getFileSize(filename);
    //char *outString = (char *) malloc(fs * sizeof(char));
    size_t outSize = 10;
    char *outString = (char *)malloc(outSize);

    if (parseAssemblyFile(filename, outString, &table) < 0) {
        return 0;
    }

    writeStringToFile("out.hack", outString);

    free(outString);

    return 0;
}