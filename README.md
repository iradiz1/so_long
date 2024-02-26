# So_Long Project

## Description
So_Long is a simple 2D game project implemented in C as part of a programming course. The game aims to provide a basic understanding of game development concepts such as rendering, user input handling, and basic game logic.

## Features
- **2D Graphics**: Rendered graphics using a simple graphic library (MLX42).
- **Map Parsing**: Parsing of map files to generate the game level dynamically.
- **Player Movement**: Basic player movement controlled via WASD keys.
- **Object Collision Detection**: Detection of collisions between the player and objects in the game world.

## Installation
1. Clone the repository:

2. Compile the program using the provided makefile:

## Usage
Run the executable with the map file as a parameter:


- Use WASD keys to move the player character.
- Close the game window to exit.

## Map File Format
Map files are formatted as `.ber` files, consisting of the following characters:
- `1`: Wall
- `0`: Empty space
- `P`: Player character
- `E`: Exit point
- `C`: Collectible item
