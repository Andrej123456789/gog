# gog

The Game of Googol written in C.

This game is related to the theory of [optimal stopping](https://en.wikipedia.org/wiki/Optimal_stopping).

[Latest release - v6.0.0](https://github.com/Andrej123456789/gog/releases/tag/v6.0.0)

## Rules

There are `x` number of cards. Each card has a number, between `1` (one) and `10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000` (googol).

You can set the maximum number to make the game easier.

Winner is a person who finds the largest number.

**Be careful, you cannot retroactively choose a card!**

## How to win

<details>
  <summary><strong>WARNING: If you want to try win this game without any help, (please) do not click me!</strong></summary>
  
  Divide the number of cards with number `e` (_2.7182818284590452353602874713527..._) and round the result to the nearest natural number. Quit playing when you find the largest number so far on a card whose index is larger than the rounded number.

Example: 10/e ≈ 4

- Card 4: 78 - CONTINUE PLAYING
- Card 5: 68 - CONTINUE PLAYING
- Card 6: 81 - QUIT

</details>

## Build & run instructions

## Installing dependencies

### Windows

- Git
- Visual Studio with C/C++ development extension
- CMake
- GMP (x64 static version from vcpkg)

### Linux

| Package: | Command:                                                                                                                      |
| -------- | ----------------------------------------------------------------------------------------------------------------------------- |
| git      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install git`</td><td>`pacman -S git`</td></tr></table>         |
| make     | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install make`</td><td>`pacman -S make`</td></tr></table>       |
| gcc      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install gcc`</td><td>`pacman -S gcc`</td></tr></table>         |
| gmp      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install libgmp3-dev`</td><td>`pacman -S gmp`</td></tr></table> |

## Compiling & running

### Windows

<details>
<summary>CMake</summary>

| Number: | Step:                                                          | Command:                                           |
| ------- | -------------------------------------------------------------- | -------------------------------------------------- |
| 1       | Clone a repository                                             | `git clone https://github.com/Andrej123456789/gog` |
| 2       | Enter the `src` folder                                         | `cd gog\src`                                       |
| 3       | Create the `build` folder                                      | `mkdir build`                                      |
| 4       | Enter the `build` folder                                       | `cd build`                                         |
| 5       | Run CMake                                                      | `cmake .. -DGMP_ROOT="path_to_vcpkg"`              |
| 6       | Open Visual Studio and build the solution                      |                                                    |
| 7       | Run the program located inside the `Debug` or `Release` folder | `.\Debug\gog.exe` or `.\Release\gog.exe`           |

</details>

<details>
<summary>CMake without Visual Studio</summary>

**Notice! You still need to have Visual Studio with C/C++ development extension installed. Run following commands inside _Developer Command Prompt_ or _Developer Powershell_.**

| Number: | Step:                     | Command:                                                                                                 |
| ------- | ------------------------- | -------------------------------------------------------------------------------------------------------- |
| 1       | Clone a repository        | `git clone https://github.com/Andrej123456789/gog`                                                       |
| 2       | Enter the `src` folder    | `cd gog\src`                                                                                             |
| 3       | Create the `build` folder | `mkdir build`                                                                                            |
| 4       | Enter the `build` folder  | `cd build`                                                                                               |
| 5       | Run CMake                 | `cmake -G "NMake Makefiles" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl -DGMP_ROOT="path_to_vcpkg" ..` |
| 6       | Compile                   | `nmake`                                                                                                  |
| 7       | Run the program           | `.\gog.exe`                                                                                              |

</details>

### Linux

<details>
<summary>Make</summary>

| Number: | Step:                     | Command:                                           |
| ------- | ------------------------- | -------------------------------------------------- |
| 1       | Clone a repository        | `git clone https://github.com/Andrej123456789/gog` |
| 2       | Enter the `src` directory | `cd gog/src`                                       |
| 3       | Compile                   | `make`                                             |
| 4       | Run the program           | `make run`                                         |

</details>

<details>
<summary>CMake</summary>

| Number: | Step:                        | Command:                                           |
| ------- | ---------------------------- | -------------------------------------------------- |
| 1       | Clone a repository           | `git clone https://github.com/Andrej123456789/gog` |
| 2       | Enter the `src` directory    | `cd gog/src`                                       |
| 3       | Create the `build` directory | `mkdir build`                                      |
| 4       | Enter the `build` directory  | `cd build`                                         |
| 5       | Run CMake                    | `cmake ..`                                         |
| 6       | Compile                      | `make`                                             |
| 7       | Run the program              | `./gog`                                            |

</details>

## Credits

- [The Game You Quit - Vsauce2](https://www.youtube.com/watch?v=OeJobV4jJG0)
- [GMP tutorial](https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html)
- [`Integer-Comparisons` GNU GMP documentation](https://gmplib.org/manual/Integer-Comparisons)
