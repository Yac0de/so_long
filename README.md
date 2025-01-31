# so_long

## Table of Contents

1. [Project Overview](#project-overview)
2. [Project Structure](#project-structure)
3. [How to Use This Project](#how-to-use-this-project)
4. [Game Mechanics](#game-mechanics)
5. [Code Structure and Key Features](#code-structure-and-key-features)
6. [Pathfinding with Binary Mask](#pathfinding-with-binary-mask)
7. [Animations](#animations)
8. [Key Learning Points](#key-learning-points)

---

## Project Overview

**so_long** is a simple 2D game where the player must collect all the items on the map before reaching the exit. The game is developed in C using the MiniLibX graphics library.

### Features:

- Character movement using **W, A, S, D** keys.
- Collectibles scattered on the map.
- A fixed exit that can only be accessed once all collectibles are gathered.
- Basic window and event management using MiniLibX.
- Enemies (`H`) that cause the player to lose if touched.
- Jumping animation and movement mechanics.
- Error handling for invalid maps.
- Memory management to prevent leaks.

## Project Structure

```
.
├── inc
├── libft
├── maps
│   ├── invalid
│   └── valid
├── src
│   ├── display_map.c
│   ├── display_map_utils.c
│   ├── free.c
│   ├── game_loop.c
│   ├── init_frames.c
│   ├── init_struct.c
│   ├── load_textures.c
│   ├── main.c
│   ├── movement.c
│   ├── read_map.c
│   ├── utils.c
│   ├── valid_map.c
│   ├── valid_map_utils.c
├── textures
├── Makefile
└── README.md
```

## How to Use This Project

### 1. Install MiniLibX

This project uses **MLX42** instead of the traditional **MiniLibX** from 42. The standard version can be found [here](https://github.com/42Paris/minilibx-linux), but **MLX42** is allowed and used in this project. To install it:

```sh
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build
cmake --build build -j$(nproc)
```

### 2. Compile the Project

```sh
make
```

### 3. Run the Game

```sh
./so_long maps/valid/map_basic.ber
```

**Warning:** If the animations appear too fast or too slow, you may need to adjust the frame delays (`jump_delay`, `hunter_delay`) in `game_loop.c` to match your system's performance. Currently, `jump_delay` is set to 50 frames and `hunter_delay` to 100 frames.

### 4. Controls

- `W` - Move up
- `A` - Move left
- `S` - Move down
- `D` - Move right
- `ESC` - Quit the game

### 5. Clean Up

```sh
make clean
make fclean
make re
```

## Game Mechanics

- The player must collect **all collectibles (`C`)** before reaching the exit (`E`).
- The player **cannot move through walls (`1`)**.
- If the player **touches an enemy (`H`), they lose immediately**.
- The game counts and displays the number of **steps** taken.
- The rabbit has **jump animations**.
- The game loop is adjusted to allow performance scaling based on the machine's capabilities.

## Code Structure and Key Features

### 1. Main Execution (`main.c`)

- Validates user input (`.ber` file format).
- Loads and initializes the game structure.
- Starts MiniLibX event hooks for movement and rendering.

### 2. Map Handling (`read_map.c`, `valid_map.c`, `valid_map_utils.c`)

- Loads the map from a `.ber` file.
- Checks that the map is **rectangular and enclosed by walls (`1`)**.
- Ensures that **all collectibles (`C`) and the exit (`E`) are reachable**.

### 3. Movement (`movement.c`)

- Handles **player movement** and **collision detection**.
- Updates **the game state**.
- Adjusts animations dynamically to maintain smooth movement.

### 4. Rendering (`display_map.c`, `display_map_utils.c`)

- Draws the initial game scene.
- Updates **individual tiles when needed**.
- Displays the number of **steps taken**.
- Manages **animations**.
- Ensures proper **layering of textures**.

### 5. Game Loop (`game_loop.c`)

- Continuously updates animations.
- Checks **win/loss conditions** and displays a **message**.
- Closes the game window when finished.
- Frame delays (`jump_delay`, `hunter_delay`) are adjustable for performance tuning.

### 6. Memory Management (`free.c`)

- Properly **frees all allocated memory**.
- Avoids **memory leaks**.

## Pathfinding with Binary Mask

In `valid_map.c`, a binary mask is used to check for valid paths. Each tile in the map is checked recursively using the function `check_path`, which marks traversed tiles using a bitwise operation.

- The most significant bit (`0b10000000`) is used as a **visited flag**.
- The function `check_path` recursively explores neighboring tiles to determine if a path exists from the player (`P`) to the exit (`E`) and from collectibles (`C`) back to the player.
- The map is then cleaned up by resetting the mask using `clean_map` after validation.

## Animations

Animations in the game include the movement of the player (rabbit) and enemies (hunter).

### Rabbit Animation:
- The rabbit changes orientation based on movement direction.
- A jump animation sequence is triggered when the player moves.
- The animation consists of 4 frames and updates every 50 frames.
- Once the jump animation completes, it resets and allows the player to move again.

### Hunter Animation:
- The enemy (hunter) cycles through 4 animation frames.
- Every 100 frames, the next frame is activated while the previous one is disabled.
- This creates a simple idle animation that loops continuously.

These animations are managed in `movement.c` and `game_loop.c`, ensuring smooth and dynamic gameplay.

## Key Learning Points

This project reinforced several important programming concepts:

- **Graphics programming**.
- **File parsing and validation**.
- **Event-driven programming**.
- **Memory management**.

---
