#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

static void createTestFile(char *filename, char *data) {
    FILE *fptr;
    fptr = fopen(filename, "w");
    fprintf(fptr, "%s", data);
    fclose(fptr);
}

int readFileIntoString_GivenEmptyFile_LeavesStringEmpty() {
    char *filename = "test.txt";
    createTestFile(filename, "");
    char str[0];

    readFileIntoString(filename, str);

    int isFail = assertStringEqual("", str, "readFileIntoString()");

    remove(filename);

    return isFail;
}

int readFileIntoString_PopulatesString() {
    char *filename = "test.txt";
    createTestFile(filename, "abcd123");
    char str[10];

    readFileIntoString(filename, str);

    int isFail = assertStringEqual("abcd123", str, "readFileIntoString()");

    remove(filename);

    return isFail;
}