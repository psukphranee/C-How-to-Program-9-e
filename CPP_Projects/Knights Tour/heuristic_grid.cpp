#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

/*This .cpp file is a test of my heuristic algorithm that will
be used in main.cpp to move the knight around the board
*/

/*The two arrays below will be index in pairs. The pair of numbers
correpond to the horizontal and vertical offsets of each of the Knight's L-shaped moves. For example,
(horizontal[0], vertical[0]) = (2, -1)
is the offset from starting position of one of the eight possible moves.
*/
array<int, 8> horizontal = {2,1,-1,-2,-2,-1,1,2};
array<int, 8> vertical = {-1,-2,-2,-1,1,2,2,1};

const size_t gridSize = 8;

int possibleMoves(int, int);
void possibleMoves(int, int, array<array<int, gridSize>, 2> &); //determines indices of the surrounding 8 moves, given some current position indice pair.
void printGrid(array<array<int, gridSize>, gridSize> &);
void labelHeuristic(array<array<int, gridSize>, gridSize> &);
int countPossible(array<array<int, gridSize>, 2> &);

int main()
{
  array<array<int, gridSize>,gridSize> gridHeuristic = {}; //Make an empty heuristic grid
  //pass gradeHeurisitc to the labelHeuristic() function to populate each grid with a count
  //of possible L-shaped moves
  labelHeuristic(gridHeuristic);
  printGrid(gridHeuristic);
}

void labelHeuristic(array<array<int, gridSize>, gridSize> &gridHeuristic)
{
  array<array<int, gridSize>, 2> nextCoordinates = {};

  for(int i = 0; i < gridSize; ++i){
    for(int j = 0; j < gridSize; ++j){
      /*
      This nested for-loop iterates through the entire gameboard, using
      counters i and j. (row, column) = (i, j). It populates the 2D girdHeuristic array
      with counts of the possible surrounding moves for each position. Possible moves are
      L-shaped moves that a knight can make that are in the boards bounds.
      This is a 2-step process. The possibleMoves() function finds the surrounding indices and
      countPossible() counts the ones that are in bounds.
      */
      possibleMoves(i, j, nextCoordinates);
      gridHeuristic[i][j] = countPossible(nextCoordinates);
    }
  }
}

void possibleMoves(int row_0, int col_0, array<array<int, gridSize>, 2> &nextMoves){
  for(int i = 0; i < gridSize; ++i){
    /*
    This function populates the 2D array nextMoves with indices
    of the 8 surrounding grid positions that a knight can move to, given the
    current position indices row_0 and col_0. The gameboard bounds are not considered
    here. Out of bounds indices will be filtered out with another function.
    For example, if the current position is row_0=0 and col_0=0, the nextMoves array will be
    {
      {2,1,-1,-2,-2,-1,1,2},
      {-1,-2,-2,-1,1,2,2,1}
    }
    Written in (row, col) format, we have (2, -1), (1, -2), (-1, -2), ...
    */
    nextMoves[0][i] = row_0 + horizontal[i];
    nextMoves[1][i] = col_0 + vertical[i];
  }
}

int countPossible(array<array<int, gridSize>, 2> &nextMoves){
  /*
  This function takes a 2D grid the nextMoves array that is populated by the possibleMoves() function.
  The nextMoves first and second rows correspond to indices of row and column indices of the gameboard, respectively.
  This function iterates through nextMoves arrays rows in pairs and counts the number of pairs that are in the boards
  bounds. The count is returned by the function.
  */
  int gridValue = 0;
  for(int i = 0; i < gridSize; ++i){
    if((nextMoves[0][i] <= 7) && (nextMoves[0][i] >=0)){
      if((nextMoves[1][i] <= 7) && (nextMoves[1][i] >=0)){
        ++gridValue;
      }
    }
  }
  return gridValue;
}

void printGrid(array<array<int, gridSize>, gridSize> &grid)
{
  for(auto const &row: grid){
    for(int i = 0; i < gridSize; ++i)
      cout << setw(3) << row[i];
    cout << endl;
  }
}
