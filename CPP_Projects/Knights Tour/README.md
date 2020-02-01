# Knights Tour Puzzle

## Introduction

One of the more interesting puzzles for chess buffs is the Knights Tour problem. The question is this: Can the chess piece called the knight move around an empty chessboard and touch each of the 64 squares once and only once?

An intuition of a solution is developed by running this puzzle by hand. Spaces towards the edge of the board are harder to access, meaning there are fewer spots to jump to and from to get to it. For example, the corner spaces can be accessed by only two spaces. So we have to be careful not to traversed those two spaces without hitting the corner space.

Each spot on the board can be labeled with an accessibility value, given by how many surrounding spaces can be accessed from that spot. In the case of the corner space, we'll give it an accessibility value of 2.

We use this labeling scheme to develop a heuristic for the game board. Using such information, we'll traverse the least accessible spots first. In the event where more the surrounding spots are tied for least accessibility value, we'll randomly select a spot to traverse.

## Solution

### Developing an Intuition by Hand

Starting at random positions, I traversed through the game board as the Knight piece until all possible moves were exhausted. I found that it's best to traverse through the corner and edge positions first and work my way in to the middle of the board.

### Heuristic

The algorithm uses a heuristic to guide its movements. The heuristic is a grid populated with values corresponding to the number of possible valid moves from each grid position. The file **heuristic_grid.cpp** contains the code that creates such a heuristic. It creates the heuristic grid and prints it for the verication.

### Algorithm

**main.cpp** creates a gameboard and heuristic board. After populating the heuristic board with the code taken from **heuristic_grid.cpp**, it randomly selects a starting position on the gameboard. Using the heuristic grid as a guide, it traverses the board prioritizing the edge and corner positions. The starting position is labeled 0. Subsequent moves are labeled with incrementing values starting from 0. The result is printed.
