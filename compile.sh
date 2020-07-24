#!/usr/bin/env bash
mkdir -p ./bin
gcc -Wall -pedantic -o bin/client -Iinclude ./src/*.c