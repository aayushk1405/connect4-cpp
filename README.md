# Connect4 (C++)

A console-based implementation of the classic Connect4 game written in C++ using object-oriented programming principles.  
The game is played between two players on a 7×7 grid, where players take turns dropping coins into columns.  
The first player to achieve four consecutive coins in a row, column, or diagonal wins the game.

---

## Features
- Two-player console gameplay
- Dynamic board initialization
- Win detection for rows, columns, and diagonals
- Object-oriented design using classes
- Turn-based gameplay with input validation

---

## File Structure
- `Main.cpp` — Handles game flow and user interaction
- `Connect4Game.h` — Class definition for the Connect4 game
- `Connect4Game.cpp` — Implementation of game logic and rules

---

## How to Compile and Run

### Compile:
```bash
g++ Main.cpp Connect4Game.cpp -o connect4

