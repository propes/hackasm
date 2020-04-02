#include <stdio.h>
#include <string.h>
#include "lib/test.h"
#include "hackAssemblerLib.h"

int stripWhiteSpace_GivenValues() {
    char * testData[][3] = {
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
        char * value = testData[i][0];
        char * expected = testData[i][1];
        char * testName = testData[i][2];

        char result[strlen(value)];
        stripWhiteSpace(value, result);

        failCount += assertStringEqual(expected, result, testName);
    }

    return failCount;
}

int main() {
    int failCount =
        stripWhiteSpace_GivenValues();

    if (failCount == 0) {
        printf("All tested passed.\n");
    }

    return 0;
}