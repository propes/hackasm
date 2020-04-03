#include <stdio.h>
#include "hackAssemblerLib.h"

int main(int argc, char *argv[]) {

    char filename[] = argv[0];

    char * symbols[64][2] = {
        { "R0", "0" },
        { "R1", "1" },
        { "R2", "2" },
    };

    size_t fs = getFileSize(filename);
    char* fileString[fs];

    openFileIntoString(filename, fileString);

    char *outString = (char *) malloc(fs * sizeof(char));

    convertAssemblyToMachineCode(fileString, outString, symbols);

    writeStringToFile("out.hack", outString);

    free(outString);

    return 0;
}