# Knights Tour Puzzle

## Introduction

One of the more interesting puzzles for chess buffs is the Knights Tour problem. The question is this: Can the chess piece called the knight move around an empty chessboard and touch each of the 64 squares once and only once?

An intuition of a solution is developed by running this puzzle by hand. Spaces towards the edge of the board are harder to access, meaning there are fewer spots to jump to and from to get to it. For example, the corner spaces can be accessed by only two spaces. So we have to be careful not to traversed those two spaces without hitting the corner space.

Each spot on the board can be labeled with an accessibility value, given by how many surrounding spaces can be accessed from that spot. In the case of the corner space, we'll give it an accessibility value of 2.

We use this labeling scheme to develop a heuristic for the game board. Using such information, we'll traverse the least accessible spots first. In the event where more the surrounding spots are tied for least accessibility value, we'll randomly select a spot to traverse.

## Solution

### Developing an Intuition by Hand

Starting at random positions, I traversed through the game board by hand as the Knight piece until all possible moves were exhausted. I found that it's best to traverse through the board, prioritizing corner and edge positions, working my way in to the middle of the board.

### Heuristic

The algorithm uses a heuristic to guide its movements. The heuristic is a grid populated with values corresponding to the number of possible valid moves from each grid position. The file **heuristic_grid.cpp** contains the code that creates such a heuristic. It creates the heuristic grid and prints it for the verification.

<pre>(base) <font color="#8AE234"><b>broncop@BroncoP</b></font>:<font color="#729FCF"><b>~/Documents/C++/CPP11/CPP_Projects/Knights Tour</b></font>$ ./heuristic
  2  3  4  4  4  4  3  2
  3  4  6  6  6  6  4  3
  4  6  8  8  8  8  6  4
  4  6  8  8  8  8  6  4
  4  6  8  8  8  8  6  4
  4  6  8  8  8  8  6  4
  3  4  6  6  6  6  4  3
  2  3  4  4  4  4  3  2
</pre>

### Algorithm

**main.cpp** creates a gameboard and heuristic board. After populating the heuristic board with the code taken from **heuristic_grid.cpp**, it prompts the user for a starting position on the gameboard. Using the heuristic grid as a guide, it traverses the board prioritizing the edge and corner positions. The starting position is labeled 0. Subsequent moves are labeled with incrementing values starting from 0. The result is printed.

<pre>(base) <font color="#8AE234"><b>broncop@BroncoP</b></font>:<font color="#729FCF"><b>~/Documents/C++/CPP11/CPP_Projects/Knights Tour</b></font>$ ./a.out
Enter initial row and column [0,7]: 4, 8
Current row: 4
Current col: 0
Movement counter: 1
Gameboard:
 11 44 13 28  9 42 23 26
 14 29 10 43 24 27  8 41
 45 12  0 38 55  0 25 22
 30 15 54 61 58 37 40  7
  1 46 59 56 39 52 21 36
 16 31 62 53 60 57  6 51
 47  2 33 18 49  4 35 20
 32 17 48  3 34 19 50  5
62 moves.
(base) <font color="#8AE234"><b>broncop@BroncoP</b></font>:<font color="#729FCF"><b>~/Documents/C++/CPP11/CPP_Projects/Knights Tour</b></font>$
</pre>
