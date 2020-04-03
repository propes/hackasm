extern void createTestFile(char *filename, char *data);
extern void fillStringWithDummyData(char *str, int len);
extern int fileSize_GivenEmptyFile_ReturnsZero();
extern int fileSize_GivenOneByteFile_ReturnsOne();
extern int fileSize_Given4ByteFile_Returns4();
extern int fileSize_Given1024ByteFile_Returns1024();
extern int openFileIntoString_GivenEmptyFile_LeavesStringEmpty();
extern int openFileIntoString_PopulatesString();
extern int stripWhiteSpace_GivenValues();