# Flappy Bird

A small, from-scratch clone of the classic **Flappy Bird**, built in modern **C++17** using the **SFML 3** multimedia library. The project focuses on a clean, modular codebase (separate classes for the bird, pipes, world bounds, animation, and sprites) rather than a single monolithic game loop.

## Table of Contents

- [Features](#features)
- [Tech Stack](#tech-stack)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Building & Running](#building--running)
- [Controls](#controls)
- [How It Works](#how-it-works)
- [Assets & Credits](#assets--credits)

## Features

- Classic "flap to survive" gameplay: tap **Space** to flap and dodge scrolling pipes.
- Custom world-to-screen coordinate mapping (game logic runs in world units, decoupled from window/pixel resolution).
- Animated bird sprite driven by a small, reusable `Animation`/`Sprite` system.
- Procedurally recycled pipe pairs managed by a `PipeManager`, avoiding constant allocation/deallocation.
- AABB-based collision detection between the bird and pipes.
- Simple gravity/impulse physics for the bird's vertical movement.
- Fixed 60 FPS game loop with delta-time based updates.

## Tech Stack

- **Language:** C++17
- **Graphics/Windowing/Input:** [SFML 3](https://www.sfml-dev.org/) (`sfml-graphics`, `sfml-window`, `sfml-system`)
- **Build system:** GNU Make

## Project Structure

```
Flappy-Bird/
├── Makefile              # Build rules (compiles src/*.cpp into build/flappy_bird)
├── assets/                # Game art (backgrounds, player sprites, tiles) + credits
│   ├── Background/
│   ├── Player/
│   ├── Tiles/
│   └── readme.txt        # Original asset pack credits/license
├── include/               # Header files
│   ├── Animation.h
│   ├── Background.h
│   ├── Bird.h
│   ├── Constants.h        # Central game constants (window size, asset paths, world bounds)
│   ├── Floor.h
│   ├── Game.h
│   ├── Pipe.h
│   ├── PipeManager.h
│   ├── PipePair.h
│   ├── Sprite.h
│   ├── Utils.h            # World <-> screen coordinate/scale helpers
│   ├── World.h
│   └── WorldBounds.h
└── src/                    # Implementation files
    ├── Bird.cpp
    ├── Game.cpp
    ├── Pipe.cpp
    ├── PipeManager.cpp
    ├── PipePair.cpp
    ├── World.cpp
    └── main.cpp
```

## Prerequisites

- A C++17-capable compiler (e.g. `g++` or `clang++`)
- `make`
- **SFML 3** installed and discoverable by the linker/compiler (headers + `libsfml-graphics`, `libsfml-window`, `libsfml-system`)

### Installing SFML 3

**macOS (Homebrew):**
```bash
brew install sfml
```

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install libsfml-dev
```
> Note: some distributions still package SFML 2.x by default. If your package manager only offers SFML 2, you may need to build SFML 3 from source (see the [SFML GitHub](https://github.com/SFML/SFML)) since this project uses the SFML 3 API (`sf::Event` variants, `sf::Keyboard::Scan`, etc.).

## Building & Running

Clone the repository and build with `make`:

```bash
git clone https://github.com/Shumais-Ali06/Flappy-Bird.git
cd Flappy-Bird

# Compile (outputs build/flappy_bird)
make

# Compile and immediately run
make run
```

The compiled binary expects the `assets/` folder to be reachable via a relative path (`assets/...`), so run it from the project root:

```bash
./build/flappy_bird
```

To clean build artifacts:

```bash
make clean
```

## Controls

| Key            | Action        |
|----------------|---------------|
| `Space`        | Flap / jump   |
| Close window   | Quit the game |

## How It Works

- `main.cpp` owns the game loop: it repeatedly processes input events, updates game state by the elapsed frame time (`dt`), and renders a frame — capped at 60 FPS via `Game::update`/`sf::RenderWindow::setFramerateLimit`.
- `Game` holds the `World` and the `sf::RenderWindow`, and dispatches SFML events (window close, key presses) to game logic. Pressing `Space` calls `Bird::jump()`.
- `World` owns the `Background`, `Floor`, `Bird`, and `PipeManager`, and checks axis-aligned bounding box collisions between the bird and every active pipe pair each frame.
- `Bird` applies simple gravity/impulse physics in **world units** and clamps its vertical position to the level bounds defined in `Constants.h` / `WorldBounds.h`.
- `Utils.h` provides the coordinate conversion helpers (`worldToScnCoords`, `worldToScnSize`, etc.) that map the fixed world coordinate space to whatever pixel resolution the window is rendered at, keeping gameplay logic resolution-independent.
- `PipeManager`/`PipePair`/`Pipe` recycle a fixed pool of pipes, scrolling and repositioning them off-screen rather than continuously creating new objects.

The `Game::State` enum already defines `Playing`, `GameOver`, `Paused`, and `Menu` states; only `Playing` currently has update/render logic wired up, so the game restarts by re-launching the executable for now.

## Assets & Credits

The sprite/tile/background pack bundled in `assets/` is a third-party art pack (see `assets/readme.txt`):

- Inspired by the original **Flappy Bird** by Dong Nguyen.
- Sprites created by **Megacrash**.
- Color palette: **Endesga64**.
- Created with **Aseprite** and **Tilesetter**.
- Licensed under **Creative Commons Zero v1.0 Universal (CC0)** — free for commercial and non-commercial use.
