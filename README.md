[![Wase Engine logo banner](http://wase-engine.com/img/banner.png)](https://wase-engine.com/)

[![Website badge](https://img.shields.io/website?up_message=online&url=https%3A%2F%2Fwase-engine.com%2F)](https://wase-engine.com/)
[![Discord badge](https://img.shields.io/discord/864845724444393472?label=discord)](https://discord.gg/2RBMMxMJ7R)
[![Mit License badge](https://img.shields.io/apm/l/vim-mode)](https://github.com/Wase-Engine/blank-project/blob/master/LICENSE)
[![Issues badge](https://img.shields.io/github/issues/Wase-Engine/blank-project)](https://github.com/Wase-Engine/blank-project/issues)
![Lines badge](https://img.shields.io/tokei/lines/github/Wase-Engine/blank-project)
![Stars badge](https://img.shields.io/github/stars/Wase-Engine/blank-project?style=social)

This repository contains a blank project that is made with Wase Engine. This is a base project with only a basic window where you can extend from.

## Setting up

Requirements:

 - CMake
 - [Wase Engine](https://github.com/Wase-Engine/wase-engine)
 - SDL2
 - SDL2 image
 - SDL2 mixer
 - SDL2 ttf
 - C++17 or higher

Run the following commands to set up this project:
```
mkdir build
cd build
cmake .. -D WASE_ENGINE_INCLUDE_DIR=path -D WASE_ENGINE_LIBRARIES=path
cmake build .
```
