#include <stdio.h>
#include "tests/hackAssemblerLibTests.h"

int main() {
    int failCount =
        fileSize_GivenEmptyFile_ReturnsZero() +
        fileSize_GivenOneByteFile_ReturnsOne() +
        fileSize_Given4ByteFile_Returns4() +
        fileSize_Given1024ByteFile_Returns1024() +
        openFileIntoString_GivenEmptyFile_LeavesStringEmpty() +
        openFileIntoString_PopulatesString();

    if (failCount == 0) {
        printf("All tested passed.\n");
    }

    return 0;
}