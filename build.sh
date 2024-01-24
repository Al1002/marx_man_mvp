#!/bin/bash
cd code
make build
cd ..
source dependencies.conf
if [ -f main.cpp ]; then
    g++ main.cpp -o main.out -Llib $LIBS
fi

if [ -f main.c ]; then
    gcc main.c -o main.out -Llib $LIBS
fi