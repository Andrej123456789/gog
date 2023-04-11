# gog

The Game of Googol written in C

## Credits

- [The Game You Quit - Vsauce2](https://www.youtube.com/watch?v=OeJobV4jJG0)
- [ChatGPT](ai.com)
- [3x](https://github.com/Andrej123456789/3x)
- [GMP tutorial](https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html)
- [`Integer-Comparisons` GNU GMP documentation](https://gmplib.org/manual/Integer-Comparisons)

## Installation

### A

- Install GCC
- Install GNU GMP library

### B

- Run this command: `gcc -lm -lgmp -g .o gog gog.c && ./gog`

## Rules

You have `x` numbers of cards. Each card have a number, between `1` (one) and `10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000` (googol).

Winner is person who finds largest number.

**Be careful, you cannot retroactively choose number few cards before!**

## How to win

<details>
  <summary><strong>WARNING: If you want to try win this game without any help, (please) don't click me!</strong></summary>
  
  Divide number of cards with number `e` (_2.7182818284590452353602874713527..._) and round result to nearest natural number. When your card's position is same as result moment ago, continue playing and when you get bigger number than on card with that position, quit playing.

Example: 10/e ≈ 4

- Card 4: 78 - CONTINUE PLAYING
- Card 5: 68 - CONTINUE PLAYING
- Card 6: 81 - QUIT

</details>
