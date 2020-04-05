#include <stdio.h>
#include "tests/fileSize_tests.h"
#include "tests/stripWhiteSpace_tests.h"
#include "tests/stripComments_tests.h"
#include "tests/readSymbolsFromFile_tests.h"
#include "tests/matchRegex_tests.h"
#include "tests/addSymbol_tests.h"
#include "tests/preprocessAssemblyLine_tests.h"

int main() {
    int failCount =
        fileSize_GivenEmptyFile_ReturnsZero() +
        fileSize_GivenOneByteFile_ReturnsOne() +
        fileSize_Given4ByteFile_Returns4() +
        fileSize_Given1024ByteFile_Returns1024() +
        matchRegex_GivenNoMatch_ReturnsFalse() +
        matchRegex_GivenMatch_ReturnsTrue() +
        stripWhiteSpace_GivenValues() +
        stripComments_GivenValues() +
        readSymbolsFromFile_GivenFileDoesNotExist_ReturnErrorCode() +
        readSymbolsFromFile_GivenEmptyFile_ReturnErrorCode() +
        readSymbolsFromFile_GivenInvalidFile_ReturnErrorCode() +
        readSymbolsFromFile_GivenValidFile_ReturnSuccessCode() +
        readSymbolsFromFile_GivenSingleRecord_CreatesSymbol() +
        readSymbolsFromFile_GivenTwoRecords_CreatesSymbols() +
        readSymbolsFromFile_GivenThreeRecords_CreatesSymbols() +
        addSymbol_GivenSymbols_UpdatesArray() +
        addSymbol_GivenSymbol_UpdatesCount() +
        preprocessAssemblyLine_GivenString_ReturnsCorrectOutput() +
        preprocessAssemblyLine_GivenEmptyOrNewline_DoesntIncrementLineCounter() +
        preprocessAssemblyLine_GivenValidString_IncrementsLineCounter() +
        preprocessAssemblyLine_GivenLabel_AddLabelToSymbolsTable();

    if (failCount == 0) {
        printf("All tested passed.\n");
    }

    return 0;
}