# 2048 (C++)

A simple C++ implementation of the **2048** puzzle game.

## Overview
- `modele.h` / `modele.cpp`: board state, move/merge logic, random tile spawn
- `2048.cpp`: main game loop (terminal UI)
- `2048test.cpp`: basic unit tests
- `makefile`: build targets
- `projet.pdf`: project description

## Build
```sh
make
```

## Run
```sh
./2048
```
## Controls
- Arrow keys (or WASD) to move tiles
- Goal: reach **2048**, then keep playing for a higher score

## Tests
```sh
g++ -std=c++17 2048test.cpp modele.cpp -o 2048test
./2048test
```
## Possible extensions
- Score persistence
-	Undo / redo
-	AI player
