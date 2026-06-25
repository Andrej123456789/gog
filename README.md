# gog

The Game of Googol written in C

GPL-2.0 license

[v1.0.0](https://github.com/Andrej123456789/gog/releases/tag/v1.0.0)

[v2.0.0](https://github.com/Andrej123456789/gog/releases/tag/v2.0.0)

[v3.0.0](https://github.com/Andrej123456789/gog/releases/tag/v3.0.0)

## Credits

- [The Game You Quit - Vsauce2](https://www.youtube.com/watch?v=OeJobV4jJG0)
- [GMP tutorial](https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html)
- [`Integer-Comparisons` GNU GMP documentation](https://gmplib.org/manual/Integer-Comparisons)

## Compile

## Installing dependencies

### Windows

- Git
- Visual Studio with C/C++ development extension
- CMake
- GMP (x64 static version from vcpkg)

### Linux

| Package: | Command:                                                                                                                      |
| -------- | ----------------------------------------------------------------------------------------------------------------------------- |
| Git      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install git`</td><td>`pacman -S git`</td></tr></table>         |
| Make     | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install make`</td><td>`pacman -S make`</td></tr></table>       |
| GCC      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install gcc`</td><td>`pacman -S gcc`</td></tr></table>         |
| GMP      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install libgmp3-dev`</td><td>`pacman -S gmp`</td></tr></table> |

## Compiling & running

### Windows

| Number: | Step:                                                          | Command:                                           |
| ------- | -------------------------------------------------------------- | -------------------------------------------------- |
| 1       | Clone a repository                                             | `git clone https://github.com/Andrej123456789/gog` |
| 2       | Enter the `gog` directory                                      | `cd gog`                                           |
| 3       | Create the `build` directory and enter it                      | `mkdir build && cd build`                          |
| 4       | Run CMake                                                      | `cmake .. -DGMP_ROOT="path_to_vcpkg"`              |
| 5       | Open Visual Studio and build the solution                      |                                                    |
| 6       | Run the program located inside the `Debug` or `Release` folder | `.\Debug\gog.exe` or `.\Release\gog.exe`           |

**Notice! In order to not use Visual Studio (you still need to have it installed), you can use nmake. Run CMake with the following command: `cmake -G "NMake Makefiles" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl -DGMP_ROOT="path_to_vcpkg" ..`. To compile the project use command `nmake`.**

### Linux

| Number: | Step:                     | Command:                                           |
| ------- | ------------------------- | -------------------------------------------------- |
| 1       | Clone a repository        | `git clone https://github.com/Andrej123456789/gog` |
| 2       | Enter the `gog` directory | `cd gog`                                           |
| 3       | Compile                   | `make`                                             |
| 4       | Run the program           | `make run`                                         |

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
