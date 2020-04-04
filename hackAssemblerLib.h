#include "types.h"

extern size_t getFileSize(char *filename);
extern char* readFileIntoString(char *filename, char *str);
extern void writeStringToFile(char *filename, char *out);
extern void trimWhiteSpace(char *str, char *out);
extern char* stripComments(char *str);
extern char* addLabelsToSymbolTable(char *str, char *symbols[][2]);
extern char* parseAssemblyString(char *str, char *symbols[][2]);
extern void convertAssemblyToMachineCode(char *str, char *out, SYMBOL_TABLE *table);
extern int readSymbolsFromFile(char *filename, SYMBOL_TABLE *table);
extern int matchRegex(const char *string, char *pattern);