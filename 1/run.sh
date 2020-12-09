#!/bin/bash

gcc -c main.cpp
g++ -c main.cpp -IDownloads/include
g++ main.o -o game -lsfml-graphics -lsfml-window -lsfml-system
g++ main.o -o game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system
                      