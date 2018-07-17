/**
*  @file maze_work.cpp
*  @author Jimmy Chan
*  @version CS A257 ICA 1
*/


#include "Maze.h"

using namespace std;

int main(){
	
	cout << "Maze" << endl;
	cout << "-----------------------------" << endl;
	cout << "The user will guide a shape through the maze." << endl;
	cout << "-----------------------------" << endl;


	// Create a maze
	Maze mymaze("maze03.txt");
  
	// Print out maze
	mymaze.printMaze();
  
	cout << endl;

	while (!mymaze.onEndSpace()) {
		cout << "-----------------------------" << endl;
		cout << "'w' Move up" << endl;
		cout << "'s' Move down" << endl;
		cout << "'a' Move left (<)" << endl;
		cout << "'d' Move right (>)" << endl;
		cout << "'q' Quit" << endl;
		cout << "-----------------------------" << endl;

		cout << endl;

		cout << "Which direction? ";
		char dir;
		cin >> dir;

		switch (dir) {
		case 'w':

			if (mymaze.frontClear())
				mymaze.move();
			break;
		case 's':
			mymaze.turnRight();
			mymaze.turnRight();
			if (mymaze.frontClear())
				mymaze.move();
			mymaze.turnLeft();
			mymaze.turnLeft();
			break;
		case 'a':
			mymaze.turnLeft();
			if (mymaze.frontClear())
				mymaze.move();
			mymaze.turnRight();
			break;
		case 'd':
			mymaze.turnRight();
			if (mymaze.frontClear())
				mymaze.move();
			mymaze.turnLeft();
			break;
		case 'q':
			system("pause");
			return 0;
		}

		cout << endl;

		mymaze.printMaze();
		cout << endl;


		// Check if shape is on the end
		if (mymaze.onEndSpace())
			cout << "Win!" << endl;
	}

	system("pause");
	return 0;
}
