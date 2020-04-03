#include <stdio.h>
#include "tests/fileSize_tests.h"
#include "tests/readFileIntoString_tests.h"
#include "tests/stripWhiteSpace_tests.h"

int main() {
    int failCount =
        fileSize_GivenEmptyFile_ReturnsZero() +
        fileSize_GivenOneByteFile_ReturnsOne() +
        fileSize_Given4ByteFile_Returns4() +
        fileSize_Given1024ByteFile_Returns1024() +
        readFileIntoString_GivenEmptyFile_LeavesStringEmpty() +
        readFileIntoString_PopulatesString();

    if (failCount == 0) {
        printf("All tested passed.\n");
    }

    return 0;
}