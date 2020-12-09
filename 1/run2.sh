#!/bin/bash
gcc -c game.cpp
g++ -c game.cpp -IDownloads/include
g++ game.o -o game -lsfml-graphics -lsfml-window -lsfml-system
g++ game.o -o game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system