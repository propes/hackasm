extern int readSymbolsFromFile_GivenFileDoesNotExist_ReturnErrorCode();
extern int readSymbolsFromFile_GivenEmptyFile_ReturnErrorCode();
extern int readSymbolsFromFile_GivenInvalidFile_ReturnErrorCode();
extern int readSymbolsFromFile_GivenValidFile_ReturnSuccessCode();
extern int readSymbolsFromFile_GivenSingleRecord_CreatesSymbol();
extern int readSymbolsFromFile_GivenTwoRecords_CreatesSymbols();
extern int readSymbolsFromFile_GivenThreeRecords_CreatesSymbols();