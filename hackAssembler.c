#include <stdio.h>
#include "hackAssemblerLib.h"

int main(char * filename) {
    // TODO: add data
    char * symbols[][2] = {
        { "R0", "0" },
        { "R1", "1" }
    };

    char * str = openFileIntoString(filename);

    char * out = convertAssemblyToMachine(str, out, symbols);

    writeStringToFile(out);

    return 0;
}