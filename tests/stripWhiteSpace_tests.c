#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

int stripWhiteSpace_GivenValues() {
    char *testData[][3] = {
        { "", "", "stripWhiteSpace()" },
        { " ", "", "stripWhiteSpace( )" },
        { "  ", "", "stripWhiteSpace( )" },
        { "\t", "", "stripWhiteSpace(tab)" },
        { "a", "a", "stripWhiteSpace(a)" },
        { "aa", "aa", "stripWhiteSpace(aa)" },
        { " aa", "aa", "stripWhiteSpace( aa)" },
        { "aa ", "aa", "stripWhiteSpace(aa )" },
        { " aa ", "aa", "stripWhiteSpace( aa )" },
        { "\n", "\n", "stripWhiteSpace(newline)" },
        { "   \n", "\n", "stripWhiteSpace(newline)" },
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