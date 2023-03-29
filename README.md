
# Dante

The goal of this project is to generate mazes (in a reasonable amount of time), solve them (in a reasonable
amount of time), and print the solution.

## Authors

- [@Ustrafeev](https://github.com/Ustrafeev)
- [@Nellypal](https://github.com/Nellypal)

## Installation

```bash
  git clone git@github.com:Ustrafeev/dante.git ./dante
  cd dante
  make
```
    
## Usage/Examples

Generator:

```bash
./generator/generator x y [perfect]
```
x and y are the nulbers determinating to size of a maze to generate. The [perfect] argument is optional, the default generation will be an imperfect maze.

A perfect maze is a maze that has no loops and clusters.

The output is a maze (perfect or imperfect) of demanded size.

Solver:

```bash
./solver/solver maze.txt
```

File maze.txt is a text document containing a maze to resolve. The maze is rectangular, the ‘X’s represent the walls and the ’*’s represent the free spaces. “Start” is in the upper left-hand corner. “Finish” is in the bottom right-hand corner. The last line of the maze doesn't terminate with a return line.

If the maze has solution, the same maze will be displayed with 'o' for the solution path. Is there is no solution, a "no solution" message will be displayed.