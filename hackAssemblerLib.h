extern size_t getFileSize(char *filename);
extern char* openFileIntoString(char *filename, char *str);
extern void writeStringToFile(char *filename, char *out);
void stripWhiteSpace(char *str, char *out);
char* stripComments(char *str);
char* addLabelsToSymbolTable(char *str, char *symbols[][2]);
extern char* parseAssemblyString(char *str, char *symbols[][2]);
char* convertAssemblyToMachineCode(char str, char *out, char *symbols[][2]);