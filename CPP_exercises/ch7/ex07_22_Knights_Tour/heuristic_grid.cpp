#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

/*The two arrays below will be index in pairs. The pair of numbers
correpond to how many spaces the Knight positions the night piece moves horizonatally
and vertically. For example, 
(horizontal[0], vertical[0]) = (2, -1) 
is one of the eight possible moves (indexed 0-7).  
*/
array<int, 8> horizontal = {2,1,-1,-2,-2,-1,1,2};
array<int, 8> vertical = {-1,-2,-2,-1,1,2,2,1};

const size_t gridSize = 8;

int possibleMoves(int, int);
void possibleMoves(int, int, array<array<int, gridSize>, 2> &);
void printGrid(array<array<int, gridSize>, gridSize> &);
void labelHeuristic(array<array<int, gridSize>, gridSize> &);
int countPossible(array<array<int, gridSize>, 2> &);

int main()
{
  //Make a heuristic grid and print it
  array<array<int, gridSize>,gridSize> gridHeuristic = {};
  //pass gradeHeurisitc to labelHeuristic function
  labelHeuristic(gridHeuristic);
  printGrid(gridHeuristic);
}

void labelHeuristic(array<array<int, gridSize>, gridSize> &gridHeuristic)
{
  array<array<int, gridSize>, 2> nextCoordinates = {};

  for(int i = 0; i < gridSize; ++i){
    for(int j = 0; j < gridSize; ++j){
      possibleMoves(i, j, nextCoordinates);
      gridHeuristic[i][j] = countPossible(nextCoordinates);
    }
  }
}

void possibleMoves(int row_0, int col_0, array<array<int, gridSize>, 2> &nextMoves){
  for(int i = 0; i < gridSize; ++i){
    nextMoves[0][i] = row_0 + horizontal[i];
    nextMoves[1][i] = col_0 + vertical[i];
  }
}

int countPossible(array<array<int, gridSize>, 2> &nextMoves){
  //count the number of coordinates within grid bounds
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
