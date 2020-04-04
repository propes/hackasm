#include <stdio.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

static void createTestFile(char *filename, char *data) {
    FILE *fptr;
    fptr = fopen(filename, "w");
    fprintf(fptr, "%s", data);
    fclose(fptr);
}

int readSymbolsFromFile_GivenFileDoesNotExist_ReturnErrorCode() {
    int err = readSymbolsFromFile("imaginary.csv", NULL);

    int fail = assertIntEqual(-1, err, "readSymbolsFromFile - no file");

    return fail;
}

int readSymbolsFromFile_GivenEmptyFile_ReturnErrorCode() {
    char filename[] = "empty.csv";
    createTestFile(filename, "");

    int err = readSymbolsFromFile(filename, NULL);

    int fail = assertIntEqual(-1, err, "readSymbolsFromFile - empty file");

    remove(filename);

    return fail;
}

int readSymbolsFromFile_GivenInvalidFile_ReturnErrorCode() {
    char filename[] = "error.csv";
    char *testData[] = {
        "a",
        ",",
        "a,",
        ",1"
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        createTestFile(filename, testData[i]);

        int err = readSymbolsFromFile(filename, NULL);

        failCount += assertIntEqual(-1, err, "readSymbolsFromFile - invalid file");

        remove(filename);
    }

    return failCount;
}