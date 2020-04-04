#include <stdio.h>
#include <string.h>
#include "types.h"

void addSymbol(SYMBOL_TABLE *table, SYMBOL symbol) {
    int i = table->count;
    table->symbols[i] = symbol;
    table->count++;
}