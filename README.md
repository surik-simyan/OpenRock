# OpenRock

Reverse-engineered reimplementation of *Will Rock* (2003), with the goal of understanding, preserving, and modernizing the original codebase for cross-platform use.

## Goal

To reverse engineer the original *Will Rock* executable and reimplement its engine using cross-platform technologies, enabling portability beyond Windows.

## Status

- Early-stage reverse engineering
- Initial research into memory layout and core functions
- Planning for abstraction layer over DirectX and Win32 APIs

## Process View

The following table outlines the current status of directories found in the original game installation structure. This helps contributors identify which areas are being actively explored, which contain standard assets (like videos/audio), and which remain unexplored. 

| Directory     | Status        |   Description |
|---------------|---------------|---------------|
| `bin`         | Untouched     | Main executable with configuration files |
| `Black Box`   | Untouched     | Contains Flash website guide, not directly connected with the game but can be preserved, needs to be converted to HTML5 or integrate Ruffle |
| `database`    | Untouched     | Likely contains game data or configuration files in proprietary `.tpl` format |
| `levels`      | Untouched     | May contain level-specific assets or scripts proprietary `.dsl` format |
| `movies`      | Public Format | Contains `.mpg` video files – no further action needed |
| `register`    | Unrelevant    | Tool to register game copy – no further action needed |
| `saves`       | Untouched     | Save game files in proprietary `.wrs` format |
| `scenes`      | Untouched     | Likely contains scene-related assets or scripts in proprietary `.lg` format |
| `screenshots` | Untouched     | Contains screenshots of the game |
| `sounds`      | Public Format | Contains `.wav` audio files – no further action needed |
| `texts`       | WIP           | Contains information about strings in `.cms` and `.str` formats |
| `textures`    | Untouched     | Contains textures in proprietary `.pct` format |

## Contributing

We welcome contributions from all skill levels.  
See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

## Tools Used

So far, we're mainly using:

- **Ghidra** – NSA-developed disassembler/decompiler.
- **ImHex** – A hex editor built for reverse engineers, with pattern scanning and more.
