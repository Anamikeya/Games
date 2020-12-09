#!/bin/bash

gcc -c Main.cpp
g++ -c Main.cpp -IDownloads/include
g++ Main.o -o Game -lsfml-graphics -lsfml-window -lsfml-system
g++ Main.o -o Game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system

gcc -c Game.cpp
g++ -c Game.cpp -IDownloads/include
g++ Game.o -o Game -lsfml-graphics -lsfml-window -lsfml-system
g++ Game.o -o Game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system

gcc -c player.cpp
g++ -c player.cpp -IDownloads/include
g++ player.o -o Game -lsfml-graphics -lsfml-window -lsfml-system
g++ player.o -o Game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system
                      
g++ Game.o Main.o player.o-o Game -lsfml-graphics -lsfml-window -lsfml-system
g++ Game.o Main.o -o player.o Game -LDownloads/lib -sfml-graphics -sfml-window -sfml-system