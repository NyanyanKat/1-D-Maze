/**
*  @file maze_demo.cpp
*  @author Jimmy Chan
*  @version CS A257 ICA 1
*/


#include "Maze.h"

using namespace std;

int main(){
  // Create a maze
  Maze mymaze("maze03.txt");
  
  // Print out maze
  mymaze.printMaze();

  // Print out current position
  mymaze.printPosition();
  
  cout << endl;
  
  // Check which directions are free
  // 0 is blocked, 1 is free
  cout << "Front: " << mymaze.frontClear() << endl;
  cout << "Left: " << mymaze.leftClear() << endl;
  cout << "Right: " << mymaze.rightClear() << endl;
  
  // Move the character to the end Note that the maze class will allow
  // the shape to be moved through a wall. You should prevent that in
  // your program without modifying the Maze class.

  mymaze.turnLeft();
  mymaze.turnLeft();

  mymaze.move();
  mymaze.move();

  mymaze.turnLeft();
  mymaze.move();
  mymaze.move();

  mymaze.turnLeft();
  mymaze.move();


  // Print out position and maze
  cout << endl;
  mymaze.printPosition();
  cout << endl;
  mymaze.printMaze();
  cout << endl;
   
  // Check if shape is on the end
  if(mymaze.onEndSpace())
    cout << "Win!" << endl;
  else
    cout << "Lose :(" << endl;


  system("pause");
  return 0;
}
