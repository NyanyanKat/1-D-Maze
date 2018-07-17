/**
*  @file Maze.cpp
*  @author Jimmy Chan
*  @version CS A257 ICA 1
*/


#include "Maze.h"
#include <fstream>
#include <iostream>


using namespace std;


// Constructor
// Character starts in top left corner facing right
// filename: the name of the maze text file
Maze::Maze(string filename){
  // Read in the maze
  ifstream file(filename);
  char newline;
  
  if(!file.fail()){
    file >> numRows;
    file >> numCols;
    
    // Create maze array
    maze = new char*[numRows];
    for(int i = 0; i < numRows; i++){
      maze[i] = new char[numCols];
      for(int j = 0; j < numCols; j++){
	file >> maze[i][j];
      }
      file.get(newline);
    }
  } else {
    cout << "Cannot open maze file" << endl;
    return;
  }
  
  // Set position and direction
  direction = NORTH;
  curRow = curCol = 0;
}


bool Maze::isWall(int row, int col){
  // Check new coordinates are valid
  // or blocked
  if(row < 0 || col < 0 || row >= numRows  || col >= numCols || maze[row][col] == '|')
    return false;

  return true;
}


// Returns whether or not the front is clear to move to
bool Maze::frontClear(){
  int row = curRow, col = curCol;

  switch(direction){
  case NORTH:
    // Facing north
    row = curRow - 1;
    break;
  case SOUTH:
    row = curRow + 1;
    break;
  case EAST:
    col = curCol + 1;
    break;
  case WEST:
    col = curCol - 1;
    break;
  }

  return isWall(row, col);
}


// Returns whether or not the left is clear to move to
bool Maze::leftClear(){
  int row = curRow, col = curCol;

  switch(direction){
  case NORTH:
    col = curCol - 1;
    break;
  case SOUTH:
    col = curCol + 1;
    break;
  case EAST:
    row = curRow - 1;
    break;
  case WEST:
    row = curRow + 1;
    break;
  }

  return isWall(row, col);
}


// Returns whether or not the right is clear to move to
bool Maze::rightClear(){
  int row = curRow, col = curCol;

  switch(direction){
  case NORTH:
    col = curCol + 1;
    break;
  case SOUTH:
    col = curCol - 1;
    break;
  case EAST:
    row = curCol + 1;
    break;
  case WEST:
    row = curCol - 1;
    break;
  }

  return isWall(row, col);
}


// Move forward one spot in the direction
// Does not verify move is valid
void Maze::move(){
  switch(direction){
  case NORTH:
    curRow--;
    break;
  case SOUTH:
    curRow++;
    break;
  case EAST:
    curCol++;
    break;
  case WEST:
    curCol--;
    break;
  }
}

// Turns character right (in place)
void Maze::turnRight(){
  switch(direction){
  case NORTH:
    direction = EAST;
    break;
  case SOUTH:
    direction = WEST;
    break;
  case EAST:
    direction = SOUTH;
    break;
  case WEST:
    direction = NORTH;
    break;
  }
}

// Turns character left (in place)
void Maze::turnLeft() {
  switch(direction){
  case NORTH:
    direction = WEST;
    break;
  case SOUTH:
    direction = EAST;
    break;
  case EAST:
    direction = NORTH;
    break;
  case WEST:
    direction = SOUTH;
    break;
  }
}


// Print Maze
void Maze::printMaze(){
  for(int i = 0; i < numRows; i++){
    for(int j = 0; j < numCols; j++){
      if(i == curRow && j == curCol){
	cout << "o";
      } else if(maze[i][j] == '.'){
	cout << " ";
      } else {
	cout << maze[i][j];
      }
    }
    cout << endl;
  }
}

// Prints out current position (for debugging)
void Maze::printPosition(){
  cout << "Current Position: " << endl;
  cout << "(" << curRow << ", " << curCol << ")" << endl;
  cout << "Facing ";
  switch(direction){
  case NORTH:
    cout << "North" << endl;
    break;
  case SOUTH:
    cout << "South" << endl;
    break;
  case EAST:
    cout << "East" << endl;
    break;
  case WEST:
    cout << "West" << endl;
    break;
    
  }
}


// Returns true if character is on the ending character
bool Maze::onEndSpace(){
  if(curRow >=0 && curCol >= 0 && curRow < numRows && curCol < numCols)
    return maze[curRow][curCol] == END_CHAR;
  
  return false;
}


// Destructor
Maze::~Maze(){
  for(int i = 0; i < numRows; i++)
    delete[] maze[i];

  delete[] maze;
} 

