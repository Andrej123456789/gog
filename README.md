# gog

The Game of Googol written in C

Public Domain

## Credits

- [The Game You Quit - Vsauce2](https://www.youtube.com/watch?v=OeJobV4jJG0)
- [GMP tutorial](https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html)
- [`Integer-Comparisons` GNU GMP documentation](https://gmplib.org/manual/Integer-Comparisons)
- [3x](https://github.com/Andrej123456789/3x)
- [ChatGPT](ai.com)

## Installation

### A

- Install GCC
- Install GNU GMP library

### B

- Run this command: `gcc -o gog gog.c -lgmp && ./gog`

## Rules

You have `x` number of cards. Each card have a number, between `1` (one) and `10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000` (googol).

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
