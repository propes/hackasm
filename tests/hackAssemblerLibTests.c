#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

void createTestFile(char *filename, char *data) {
    FILE *fptr;
    fptr = fopen(filename, "w");
    fprintf(fptr, "%s", data);
    fclose(fptr);
}

void fillStringWithDummyData(char *str, int len) {
    for (int i = 0; i < len -1; i++) {
        str[i] = 'a';
    }
    str[len-1] = '\0';
}

int fileSize_GivenEmptyFile_ReturnsZero() {
    char *filename = "empty.txt";
    createTestFile(filename, "");

    size_t size = getFileSize(filename);

    int isFail = assertIntEqual(0, size, "fileSize()");

    remove(filename);

    return isFail;
}

int fileSize_GivenOneByteFile_ReturnsOne() {
    char *filename = "size1.txt";
    createTestFile(filename, "a");

    size_t size = getFileSize(filename);

    int isFail = assertIntEqual(1, size, "fileSize()");

    remove(filename);

    return isFail;
}

int fileSize_Given4ByteFile_Returns4() {
    char *filename = "size4.txt";
    createTestFile(filename, "abcd");

    size_t size = getFileSize(filename);

    int isFail = assertIntEqual(4, size, "fileSize()");

    remove(filename);

    return isFail;
}

int fileSize_Given1024ByteFile_Returns1024() {
    char *filename = "size1024.txt";
    char str[1025]; // array has extra element for string terminator
    fillStringWithDummyData(str, 1025);
    createTestFile(filename, str);

    size_t size = getFileSize(filename);

    int isFail = assertIntEqual(1024, size, "fileSize()");

    remove(filename);

    return isFail;
}

int openFileIntoString_GivenEmptyFile_LeavesStringEmpty() {
    char *filename = "test.txt";
    createTestFile(filename, "");
    char str[0];

    openFileIntoString(filename, str);

    int isFail = assertStringEqual("", str, "openFileIntoString()");

    remove(filename);

    return isFail;
}

int openFileIntoString_PopulatesString() {
    char *filename = "test.txt";
    createTestFile(filename, "abcd123");
    char str[10];

    openFileIntoString(filename, str);

    int isFail = assertStringEqual("abcd123", str, "openFileIntoString()");

    remove(filename);

    return isFail;
}

int stripWhiteSpace_GivenValues() {
    char *testData[][3] = {
        { "", "", "stripWhitespace()" },
        { " ", "", "stripWhitespace( )" },
        { "  ", "", "stripWhitespace( )" },
        { "\t", "", "stripWhitespace(tab)" },
        { "a", "a", "stripWhitespace(a)" },
        { "aa", "aa", "stripWhitespace(a)" }
    };

    int failCount = 0;
    int testCount = sizeof(testData) / sizeof(testData[0]);

    for (int i = 0; i < testCount; i++) {
        char *value = testData[i][0];
        char *expected = testData[i][1];
        char *testName = testData[i][2];

        char result[strlen(value)];
        stripWhiteSpace(value, result);

        failCount += assertStringEqual(expected, result, testName);
    }

    return failCount;
}