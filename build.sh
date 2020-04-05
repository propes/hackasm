#!/bin/bash
if [ ! -d "lib" ]; then
    mkdir lib
fi
cp ~/code/c/test-framework/test.c lib
cp ~/code/c/test-framework/test.h lib
gcc -c -g lib/test.c
gcc -c -g hackAssemblerLib.c
gcc -c -g symbols.c
gcc -c -g tests/fileSize_tests.c
gcc -c -g tests/stripWhiteSpace_tests.c
gcc -c -g tests/readSymbolsFromFile_tests.c
gcc -c -g tests/matchRegex_tests.c
gcc -c -g tests/addSymbol_tests.c
gcc -c -g runner.c
gcc -c -g main.c

gcc -o runner \
    test.o \
    hackAssemblerLib.o \
    symbols.o \
    fileSize_tests.o \
    stripWhiteSpace_tests.o \
    readSymbolsFromFile_tests.o \
    matchRegex_tests.o \
    addSymbol_tests.o \
    runner.o

gcc -o hackAsm \
    hackAssemblerLib.o \
    symbols.o \
    main.o

rm *.o