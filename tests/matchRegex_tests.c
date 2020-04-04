#include <stdio.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

int matchRegex_GivenNoMatch_ReturnsFalse() {
    char *testData[][2] = {
        { "abc", "d" },
        { "a", "[0-9]" },
        { "1a23", "^[0-9]+$" }
    };

    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        int result = matchRegex(testData[i][0], testData[i][1]);

        char msg[50];
        snprintf(msg,
            50,
            "matchRegex(\"%s\",\"%s\")",
            testData[i][0],
            testData[i][1]); 

        failCount += assertIntEqual(0, result, msg);
    }

    return failCount;
}

int matchRegex_GivenMatch_ReturnsTrue() {
    char *testData[][2] = {
        { "abc", "a" },
        { "1", "[0-9]" },
        { "123", "[0-9]" },
        { "123", "^[0-9]+$" }
    };

    int testCount = sizeof(testData) / sizeof(testData[0]);
    int failCount = 0;

    for (int i = 0; i < testCount; i++) {
        int result = matchRegex(testData[i][0], testData[i][1]);

        char msg[50];
        snprintf(msg,
            50,
            "matchRegex(\"%s\",\"%s\")",
            testData[i][0],
            testData[i][1]); 

        failCount += assertIntEqual(1, result, msg);
    }

    return failCount;
}