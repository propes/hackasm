#include <stdio.h>
#include <string.h>
#include "types.h"

void addSymbol(SYMBOL_TABLE *table, SYMBOL symbol) {
    int i = table->count;
    strcpy(table->symbols[i].name, symbol.name);
    strcpy(table->symbols[i].value, symbol.value);
    table->count++;
}