# `SUAI` C++ Labs

A repository for learning Git, C/C++ and CMake in SUAI

[![CMake](https://github.com/cyberpotat42/SUAI-Labs/actions/workflows/cmake.yml/badge.svg)](https://github.com/cyberpotat42/SUAI-Labs/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/cyberpotat42/SUAI-Labs/actions/workflows/codeql.yml/badge.svg)](https://github.com/cyberpotat42/SUAI-Labs/actions/workflows/codeql.yml)

## Useful links

Tasks for laboratory works: [Google Docs](https://docs.google.com/document/d/1xrpJrEPfF8pt5H5FsIfXumKFvwkoEy_wYpgZskR7_lA/)  
My formatted Lab tasks: [TASKS.md](TASKS.md)  
Formatted reports: [Google Drive](https://drive.google.com/drive/folders/1gj9lEsKWZlvJXa8zt8tXn1vKMhPW0Kju)

## Build

### Requirements

- C++17 compiler (GCC, Clang, MSVC)
- CMake 3.12+ (3.20+ recommended)

Tested on:

- GCC 12.2.0 (MinGW-w64, Windows 10)
- GCC 9.4.0 (Ubuntu 20.04, WSL2)

Some labs may require additional libraries / tools:

- [nlohmann/json](https://github.com/nlohmann/json) (for Lab 17 dop)
- [Graphviz](https://graphviz.org/) (for Lab 20 dop)

### Build steps

1. Clone the repository

   ```bash
   git clone https://github.com/cypotat/cpplabs.git
   ```

2. Create a build directory

   ```bash
   mkdir build
   cd build
   ```

3. Generate build files

   ```bash
   cmake ..
   ```

4. Build the project

   ```bash
   cmake --build .
   ```

   If you want to build a specific lab, you can specify the target name

   ```bash
    cmake --build . --target Lab_20_dop
   ```

   If you want to build a debug version, you can specify the build type

   ```bash
   cmake --build . --config Debug
   ```

## Time spent on labs

[![wakatime](https://wakatime.com/badge/user/44ab2413-c50e-4335-a9cd-7990b8ed9c8b/project/40f4ff13-1639-42ba-a9dd-a503aca9302c.svg)](https://wakatime.com/@CyberPotat42)
