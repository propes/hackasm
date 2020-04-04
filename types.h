typedef struct {
    char name[50];
    char value[50];
} SYMBOL;

typedef struct {
    SYMBOL symbols[50];
    int count;
} SYMBOL_TABLE;

extern void addSymbol(SYMBOL_TABLE *table, SYMBOL symbol);