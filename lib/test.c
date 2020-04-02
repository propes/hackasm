#include <stdio.h>
#include <string.h>

int assertIntEqual(int expected, int actual, char * testName) {
    if (expected != actual) {
        printf("Test failed: %s. Expected: %d, Actual: %d.\n",
            testName,
            expected,
            actual);

        return 1;
    }

    return 0;
}

int assertStringEqual(char * expected, char * actual, char * testName) {
    if(strlen(expected) != strlen(actual) ||
       strncmp(expected, actual, strlen(expected)) != 0) {

        printf("Test failed: %s. Expected: \"%s\", Actual: \"%s\".\n",
            testName,
            expected,
            actual);

        return 1;
    }
}

int assertStringIsEmpty(char * actual, char * testName) {
    if(strlen(actual) != 0) {
        printf("Test failed: %s. Expected empty string, Actual: \"%s\".\n",
            testName,
            actual);

        return 1;
    }
}
