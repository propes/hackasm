#!/bin/bash
if [ ! -d "lib" ]; then
    mkdir lib
fi
cp ~/code/c/test-framework/test.c lib
cp ~/code/c/test-framework/test.h lib
gcc -c -g lib/test.c
gcc -c -g hackAssemblerLib.c
gcc -c -g tests/fileSize_tests.c
gcc -c -g tests/readFileIntoString_tests.c
gcc -c -g tests/stripWhiteSpace_tests.c
gcc -c -g tests/readSymbolsFromFile_tests.c
gcc -c -g tests/matchRegex_tests.c
gcc -c -g runner.c
gcc -c -g main.c

gcc -o runner \
    test.o \
    hackAssemblerLib.o \
    fileSize_tests.o \
    readFileIntoString_tests.o \
    stripWhiteSpace_tests.o \
    readSymbolsFromFile_tests.o \
    matchRegex_tests.o \
    runner.o

gcc -o hackAsm \
    hackAssemblerLib.o \
    main.o

rm *.o