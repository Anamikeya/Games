#!/bin/bash

gcc -c main.cpp
g++ -c main.cpp -IDownloads/include
g++ main.o -o game -lsfml-graphics -lsfml-window -lsfml-system
g++ main.o -o game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system

gcc -c game.cpp
g++ -c game.cpp -IDownloads/include
g++ game.o -o game -lsfml-graphics -lsfml-window -lsfml-system
g++ game.o -o game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system
                      
g++ game.o main.o -o game -lsfml-graphics -lsfml-window -lsfml-system
g++ game.o main.o -o game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system