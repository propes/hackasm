typedef struct {
    char *name;
    int value;
} SYMBOL;

extern size_t getFileSize(char *filename);
extern char* openFileIntoString(char *filename, char *str);
extern void writeStringToFile(char *filename, char *out);
extern void stripWhiteSpace(char *str, char *out);
extern char* stripComments(char *str);
extern char* addLabelsToSymbolTable(char *str, char *symbols[][2]);
extern char* parseAssemblyString(char *str, char *symbols[][2]);
extern void convertAssemblyToMachineCode(char *str, char *out, SYMBOL *symbols);
extern void getPredefinedSymbolsFromFile(char *filename, SYMBOL *symbols);