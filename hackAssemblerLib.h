#include "types.h"

extern size_t getFileSize(char *filename);
extern char* readFileIntoString(char *filename, char *str);
extern void writeStringToFile(char *filename, char *out);
extern void stripWhiteSpace(char *str, char *out);
extern void stripComments(char *str, char *out);
extern void convertAssemblyToMachineCode(char *str, char *out, SYMBOL_TABLE *table);
extern int readSymbolsFromFile(char *filename, SYMBOL_TABLE *table);
extern int matchRegex(const char *string, char *pattern);