# Mario-like Platformer

*Classic 2D platformer game built from scratch using C++ and SFML*

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white)

## Overview

A complete 2D platformer game inspired by classic Mario games, built entirely from scratch using C++ and the Simple and Fast Multimedia Library (SFML). This project demonstrates fundamental game development concepts including physics simulation, collision detection, sprite animation, and game state management.

## Key Features

- **Custom Physics Engine** - Built-in gravity, jumping mechanics, and collision detection
- **Sprite Animation System** - Smooth character animations and visual effects  
- **Level Design** - Multiple levels with increasing difficulty
- **Enemy AI** - Basic enemy movement patterns and collision behaviors
- **Game State Management** - Menu systems, level transitions, and game over states
- **Audio Integration** - Sound effects and background music support

## Technical Architecture

### Core Components

#### Entity System
- **Entity.cpp/h** - Base class for all game objects
- **Player.cpp/h** - Player character with movement, jumping, and collision
- **Enemy.cpp/h** - AI-controlled enemies with patrol behaviors
- **Block.cpp/h** - Static world elements and platforms

#### Graphics & Animation
- **Sprite.cpp/h** - Sprite rendering and management
- **Animation.cpp/h** - Frame-based animation system
- **World.cpp/h** - Level rendering and tile management

#### Game Management
- **Game.cpp/h** - Core game loop and state management
- **Platformer_Game.cpp** - Main entry point and initialization

### Technical Highlights

- **Memory Management** - Efficient object pooling and resource management
- **Collision Detection** - AABB (Axis-Aligned Bounding Box) collision system
- **Frame-Rate Independence** - Delta time-based movement and animations
- **Modular Design** - Clean separation of concerns and extensible architecture

## Built With

- **C++ Standard Library** - Core programming language
- **SFML 2.5+** - Graphics, audio, and input handling
- **Visual Studio** - Development environment
- **CMake** - Build system configuration

## Game Mechanics

### Player Controls
- **Arrow Keys / WASD** - Character movement
- **Space / Up Arrow** - Jump
- **ESC** - Pause menu

### Physics System
- **Gravity Simulation** - Realistic falling and jumping physics
- **Ground Detection** - Proper platform collision handling
- **Variable Jump Height** - Jump height based on button press duration
- **Momentum Conservation** - Smooth acceleration and deceleration

## Project Structure

```
Project/
├── Platformer_Game/
│   ├── *.cpp              # Source files
│   ├── *.h                # Header files
│   ├── assets/            # Game sprites and sounds
│   ├── sfml/              # SFML library files
│   └── levels/            # Level configuration files
├── preliminary project.pdf
└── Topic description and sketch of UI.pdf
```

## Building and Running

### Prerequisites
- Visual Studio 2017+ with C++ development tools
- SFML 2.5 or newer
- Windows operating system

### Build Instructions
```bash
# Clone the repository
git clone https://github.com/dawidbogocz/Mario_like_platformer.git

# Open in Visual Studio
# File -> Open -> Project/Solution
# Select Platformer_Game.sln

# Build and run (F5 or Ctrl+F5)
```

## Learning Outcomes

This project served as an exploration of fundamental game development concepts:

- **Game Loop Architecture** - Understanding frame-based game programming
- **2D Graphics Programming** - Sprite rendering and coordinate systems
- **Physics Simulation** - Implementing realistic movement and collision
- **Object-Oriented Design** - Creating modular, maintainable game systems
- **Performance Optimization** - Efficient rendering and update cycles

## Future Enhancements

- Power-up system implementation
- Multiple character selection
- Save/load game progress
- Level editor functionality
- Multiplayer support
- Mobile platform adaptation

## Development Notes

Created as part of computer graphics coursework to demonstrate practical application of:
- Low-level graphics programming concepts
- Real-time system design principles
- Interactive software architecture
- Game development best practices

---

**Built by [Dawid Bogocz](https://github.com/dawidbogocz)**

*Showcasing C++ programming skills and game development fundamentals*