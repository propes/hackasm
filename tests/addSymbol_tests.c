#include <stdio.h>
#include <string.h>
#include "../lib/test.h"
#include "../symbols.h"

int addSymbol_GivenSymbols_UpdatesArray() {
    SYMBOL_TABLE table;
    table.count = 0;

    SYMBOL symbol1;
    strcpy(symbol1.name, "abc");
    strcpy(symbol1.value, "123");

    SYMBOL symbol2;
    strcpy(symbol2.name, "foo");
    strcpy(symbol2.value, "bar");

    addSymbol(&table, symbol1);
    addSymbol(&table, symbol2);

    int failCount = 0;
    failCount += assertStringEqual("abc", table.symbols[0].name, "addSymbol - updates array");
    failCount += assertStringEqual("123", table.symbols[0].value, "addSymbol - updates array");
    failCount += assertStringEqual("foo", table.symbols[1].name, "addSymbol - updates array");
    failCount += assertStringEqual("bar", table.symbols[1].value, "addSymbol - updates array");

    return failCount;
}

int addSymbol_GivenSymbol_UpdatesCount() {
    SYMBOL_TABLE table;
    table.count = 0;

    SYMBOL symbol1;
    strcpy(symbol1.name, "abc");
    strcpy(symbol1.value, "123");

    SYMBOL symbol2;
    strcpy(symbol2.name, "def");
    strcpy(symbol2.value, "456");

    addSymbol(&table, symbol1);
    addSymbol(&table, symbol2);

    return assertIntEqual(2, table.count, "addSymbol - updates count");
}