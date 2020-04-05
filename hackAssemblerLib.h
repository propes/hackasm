#include "types.h"

extern size_t getFileSize(char *filename);
extern void writeStringToFile(char *filename, char *out);
extern void stripWhiteSpace(char *str, char *out);
extern void stripComments(char *str, char *out);
extern int readSymbolsFromFile(char *filename, SYMBOL_TABLE *table);
extern int matchRegex(const char *string, char *pattern);
extern int parseAssemblyFile(char *filename, char *outString, SYMBOL_TABLE *table);