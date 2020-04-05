#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../hackAssemblerLib.h"

int stripComments_GivenValues() {
    char *testData[][2] = {
        { "", "" },
        { "a", "a" },
        { "abc", "abc" },
        { "abc\n", "abc\n" },
        { "\\\\", "" },
        { "\\\\\n", "\n" },
        { "\\", "" },
        { "abc \\\\ this is a comment\n", "abc \n" },
        { "\\ this is a comment\n", "\n" }
    };

    int failCount = 0;
    int testCount = sizeof(testData) / sizeof(testData[0]);

    for (int i = 0; i < testCount; i++) {
        char *value = testData[i][0];
        char *expected = testData[i][1];

        char result[strlen(value)];
        stripComments(value, result);

        char msg[50];
        snprintf(msg, 50, "stripComments - \"%s\"", value);

        failCount += assertStringEqual(expected, result, msg);
    }

    return failCount;
}