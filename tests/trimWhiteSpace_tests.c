#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

int trimWhiteSpace_GivenValues() {
    char *testData[][3] = {
        { "", "", "trimWhiteSpace()" },
        { " ", "", "trimWhiteSpace( )" },
        { "  ", "", "trimWhiteSpace( )" },
        { "\t", "", "trimWhiteSpace(tab)" },
        { "a", "a", "trimWhiteSpace(a)" },
        { "aa", "aa", "trimWhiteSpace(aa)" },
        { " aa", "aa", "trimWhiteSpace( aa)" },
        { "aa ", "aa", "trimWhiteSpace(aa )" },
        { " aa ", "aa", "trimWhiteSpace( aa )" },
    };

    int failCount = 0;
    int testCount = sizeof(testData) / sizeof(testData[0]);

    for (int i = 0; i < testCount; i++) {
        char *value = testData[i][0];
        char *expected = testData[i][1];
        char *testName = testData[i][2];

        char result[strlen(value)];
        trimWhiteSpace(value, result);

        failCount += assertStringEqual(expected, result, testName);
    }

    return failCount;
}