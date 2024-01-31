#include "Space.h"
#include <iostream>

using namespace std; 
void displayCoords(Space& obj, char coords[]) {
	int* a = nullptr; 
	a = obj.getPosition();
	for (int i = 0; i < 3; i++) {
		cout << coords[i] << " = " << a[i] << endl;
	} 
}

void cinCheck(int& num) {
	if (!cin.good()) {
		cout << "\nInput is invalid! Exiting program....."; 
		exit(-2); 
	}
}

int main() {
	// create object
	Space obj; // uses default constructor
	int move;
	int input; 
	int rotate; 
	int arrPos[3]; // array to hold points
	char arrCoord[] = { 'X', 'Y', 'Z' }; // parrelel array of which point 

	// loop for user to assing points values
	for (int i = 0; i < 3; i++) {
		cout << "Input coordinate position for " << arrCoord[i] << "!\n" << arrCoord[i] << " = ";
		cin >> input; 
		cinCheck(input); 
		arrPos[i] = input; 
	}
	// Space obj_1; // uses overloaded constructor
	obj.setPosition(arrPos[0], arrPos[1], arrPos[2]); // sets the inputed points for object
	
	// display obj coords
	cout << "\nCoordinate positions of object.....\n";
	displayCoords(obj, arrCoord); 

	// move x point 
	cout << "\nMove X....." << endl;
	cout << "Move X -> "; 
	cin >> move; 
	cinCheck(move); 
	obj.moveAlongX(move); 
	cout << "\nNew Coordiantes....." << endl;
	displayCoords(obj, arrCoord); 

	// move y point
	cout << "\nMove Y....." << endl;
	cout << "Move Y -> ";
	cin >> move;
	cinCheck(move);
	obj.moveAlongY(move);
	cout << "\nNew Coordiantes....." << endl;
	displayCoords(obj, arrCoord);

	// move z point
	cout << "\nMove Z....." << endl;
	cout << "Move Z -> ";
	cin >> move;
	cinCheck(move); 
	obj.moveAlongZ(move);
	cout << "\nNew Coordiantes....." << endl;
	displayCoords(obj, arrCoord);

	// rotate around X
	cout << "\nRotate around X....." << endl;
	cout << "Rotate X by -> "; 
	cin >> rotate; 
	cinCheck(rotate); 
	obj.rotateAroundX(rotate); 
	cout << "\nNew Coordiantes....." << endl;
	displayCoords(obj, arrCoord); 

	// rotate around Y
	cout << "\nRotate around Y....." << endl;
	cout << "Rotate Y by -> ";
	cin >> rotate;
	cinCheck(rotate);
	obj.rotateAroundY(rotate);
	cout << "\nNew Coordiantes....." << endl;
	displayCoords(obj, arrCoord);

	// rotate around Z
	cout << "\nRotate around Z....." << endl;
	cout << "Rotate Z by -> ";
	cin >> rotate;
	cinCheck(rotate);
	obj.rotateAroundZ(rotate);
	cout << "\nNew Coordiantes....." << endl;
	displayCoords(obj, arrCoord);

	return EXIT_SUCCESS; 
}