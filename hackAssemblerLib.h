extern char* openFileIntoString(char* filename);
extern void writeStringToFile(char* out);
void stripWhiteSpace(char * str, char * out);
char* stripComments(char* str);
char* addLabelsToSymbolTable(char* str, char* symbols[][2]);
extern char* parseAssemblyString(char* str, char* symbols[][2]);
char* convertAssemblyToMachine(char* str, char* out, char symbols[][2]);