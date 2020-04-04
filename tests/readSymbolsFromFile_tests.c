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

int readSymbolsFromFile_GivenFileDoesNotExist_ReturnErrorCode() {
    int err = readSymbolsFromFile("imaginary.csv", NULL);

    return assertIntEqual(-1, err, "readSymbolsFromFile - no file");
}

int readSymbolsFromFile_GivenEmptyFile_ReturnErrorCode() {
    char filename[] = "empty.csv";
    createTestFile(filename, "");
    SYMBOL_TABLE table;

    int err = readSymbolsFromFile(filename, &table);

    int fail = assertIntEqual(-1, err, "readSymbolsFromFile - empty file");

    remove(filename);

    return fail;
}

int readSymbolsFromFile_GivenInvalidFile_ReturnErrorCode() {
    char filename[] = "invalid.csv";
    char *testData[] = {
        "a",
        ",",
        "a,",
        ",1",
        "a,a",
        " ,",
        ", ",
        "\n"
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        createTestFile(filename, testData[i]);
        SYMBOL_TABLE table;

        int err = readSymbolsFromFile(filename, &table);

        failCount += assertIntEqual(-1, err, "readSymbolsFromFile - invalid &file");

        remove(filename);
    }

    return failCount;
}

int readSymbolsFromFile_GivenValidFile_ReturnSuccessCode() {
    char filename[] = "valid.csv";
    char *testData[] = {
        "a,1",
        "abc,123",
        " abc , 123 ",
        "abc, 123\n",
        "a,1\n",
        "a, 1\nb, 2\nc, 3"
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        createTestFile(filename, testData[i]);
        SYMBOL_TABLE table;
        table.count = 0;

        int err = readSymbolsFromFile(filename, &table);

        char msg[50];
        snprintf(msg, 50, "readSymbolsFromFile - \"%s\"", testData[i]);

        failCount += assertIntEqual(0, err, msg);

        remove(filename);
    }

    return failCount;
}

int readSymbolsFromFile_GivenSingleRecord_CreatesSymbol() {
    char filename[] = "test.csv";
    char *testData[][3] = {
        { "a,1", "a", "1" },
        { " a , 1 ", "a", "1" },
        { "ab_c , 001\n", "ab_c", "001" },
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        char *testString = testData[i][0];
        char *expName = testData[i][1];
        char *expValue = testData[i][2];

        createTestFile(filename, testString);
        SYMBOL_TABLE table;
        table.count = 0;

        int err = readSymbolsFromFile(filename, &table);

        char msg[50];
        snprintf(msg, 50, "readSymbolsFromFile - \"%s\"", testString);

        failCount += assertStringEqual(expName, table.symbols[0].name, msg);
        failCount += assertStringEqual(expValue, table.symbols[0].value, msg);

        remove(filename);
    }

    return failCount;
}

int readSymbolsFromFile_GivenTwoRecords_CreatesSymbols() {
    char filename[] = "test.csv";
    int failCount = 0;

    char *testString = "a, 1\nb, 2";

    createTestFile(filename, testString);
    SYMBOL_TABLE table;
    table.count = 0;

    int err = readSymbolsFromFile(filename, &table);

    char msg[] = "readSymbolsFromFile - 2 records";

    failCount += assertStringEqual("a", table.symbols[0].name, msg);
    failCount += assertStringEqual("1", table.symbols[0].value, msg);
    failCount += assertStringEqual("b", table.symbols[1].name, msg);
    failCount += assertStringEqual("2", table.symbols[1].value, msg);
    failCount =+ assertIntEqual(2, table.count, msg);

    remove(filename);

    return failCount;
}

int readSymbolsFromFile_GivenThreeRecords_CreatesSymbols() {
    char filename[] = "test.csv";
    int failCount = 0;

    char *testString = "a, 1\nb, 2\nc, 3";

    createTestFile(filename, testString);
    SYMBOL_TABLE table;
    table.count = 0;

    int err = readSymbolsFromFile(filename, &table);

    char msg[] = "readSymbolsFromFile - 2 records";

    failCount += assertStringEqual("a", table.symbols[0].name, msg);
    failCount += assertStringEqual("1", table.symbols[0].value, msg);
    failCount += assertStringEqual("b", table.symbols[1].name, msg);
    failCount += assertStringEqual("2", table.symbols[1].value, msg);
    failCount += assertStringEqual("c", table.symbols[2].name, msg);
    failCount += assertStringEqual("3", table.symbols[2].value, msg);
    failCount =+ assertIntEqual(3, table.count, msg);

    remove(filename);

    return failCount;
}