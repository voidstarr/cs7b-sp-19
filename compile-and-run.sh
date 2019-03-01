#!/bin/bash

clang++-4.0 -o build/asdf main.cpp -I$HOME/lib/sfml-2.5.1/include/ -L$HOME/lib/sfml-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

LD_LIBRARY_PATH=$HOME/lib/sfml-2.5.1/lib ./build/asdf
