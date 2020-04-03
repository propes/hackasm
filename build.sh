#!/bin/bash
if [ ! -d "lib" ]; then
    mkdir lib
fi
cp ~/code/c/test-framework/test.c lib
cp ~/code/c/test-framework/test.h lib
gcc -c -g lib/test.c
gcc -c -g hackAssemblerLib.c
gcc -c -g tests/hackAssemblerLibTests.c
gcc -c -g runner.c
gcc -o runner \
    test.o \
    hackAssemblerLib.o \
    hackAssemblerLibTests.o \
    runner.o
rm *.o