/**
*  @file Maze.h
*  @author Jimmy Chan
*  @version CS A257 ICA 1
*/


#include <string>
#include <iostream>

class Maze{
 public:

  Maze(std::string filename); // Constructor
  // Maze(Maze& other); // Copy Constructor; implement if you want it
  ~Maze(); // Destructor
  
  // Returns whether or not the front, left, or right (respectively)
  // is clear to move to
  bool frontClear(); 
  bool leftClear();
  bool rightClear();
  
  // Moves the character one space in the direction it is facing
  // DOES NOT CHECK IF THE MOVE IS VALID BEFORE MOVING
  void move();

  // Turns the character right or left in place
  void turnRight();
  void turnLeft();

  // Print Maze
  void printMaze();
  
  // Prints out current position (for debugging)
  void printPosition();
  
  // Returns true if character is on the ending character
  bool onEndSpace();

 private:
  enum {NORTH, SOUTH, EAST, WEST};

  static const char END_CHAR = '$';
  char** maze; // holds the maze
  int numRows;
  int numCols;
  int direction; // direction character is facing

  // Character's position
  // 0-based Index
  int curRow; 
  int curCol;

  // Utility Functions
  bool isWall(int row, int col);
};

