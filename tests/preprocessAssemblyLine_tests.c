#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

int preprocessAssemblyLine_GivenString_ReturnsCorrectOutput() {
    char *testData[][2] = {
        { "", "" },
        { " ", "" },
        { "a", "a" },
        { "abc", "abc" },
        { "ab c", "abc" },
        { "abc \\ some comment", "abc" },
        { "\n", "" },
        { "   \n", "" },
        { "(abc)", "" }
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        char *testString = testData[i][0];
        char *expected = testData[i][1];

        SYMBOL_TABLE table;
        table.count = 0;
        char out[50] = "";
        int line = 0;

        preprocessAssemblyLine(testString, out, &line, &table);

        char msg[50];
        snprintf(msg, 50, "preprocessAssemblyLine - \"%s\"", testString);

        failCount += assertStringEqual(expected, out, msg);
    }

    return failCount;
}

int preprocessAssemblyLine_GivenEmptyOrNewline_DoesntIncrementLineCounter() {
    char *testData[] = {
        "",
        " ",
        "\n",
        "   \n",
        "(abc)"
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        SYMBOL_TABLE table;
        table.count = 0;
        char out[50] = "";
        int line = 0;

        preprocessAssemblyLine(testData[i], out, &line, &table);

        char msg[50];
        snprintf(msg, 50, "preprocessAssemblyLine - \"%s\"", testData[i]);

        failCount += assertIntEqual(0, line, msg);
    }

    return failCount;
}

int preprocessAssemblyLine_GivenValidString_IncrementsLineCounter() {
    char *testData[] = {
        "a",
        "abc",
        "ab c",
        "abc \\ some comment"
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        SYMBOL_TABLE table;
        table.count = 0;
        char out[50] = "";
        int line = 0;

        preprocessAssemblyLine(testData[i], out, &line, &table);

        char msg[50];
        snprintf(msg, 50, "preprocessAssemblyLine - \"%s\"", testData[i]);

        failCount += assertIntEqual(1, line, msg);
    }

    return failCount;
}

int preprocessAssemblyLine_GivenLabel_AddLabelToSymbolsTable() {
    char *testData[][3] = {
        { "(a)", "a", "0" },
        { "(abc)", "abc", "0" },
    };
    
    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        char *testString = testData[i][0];
        char *expName = testData[i][1];
        char *expValue = testData[i][2];

        SYMBOL_TABLE table;
        table.count = 0;
        char out[50] = "";
        int line = 0;

        preprocessAssemblyLine(testString, out, &line, &table);

        char msg[50];
        snprintf(msg, 50, "preprocessAssemblyLine - \"%s\"", testString);

        failCount += assertStringEqual(expName, table.symbols[0].name, msg);
        failCount += assertStringEqual(expValue, table.symbols[0].value, msg);
    }

    return failCount;
}