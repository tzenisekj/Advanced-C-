#include "Space.h"
#include <cmath>

Space::Space() {
	x = 0; 
	y = 0; 
	z = 0; 
}

Space::Space(int& x, int& y, int& z) {
	this->x = x; 
	this->y = y; 
	this->z = z; 
}

void Space::setPosition(int& x, int& y, int& z) {
	this->x = x; 
	this->y = y; 
	this->z = z; 
}

int * Space::getPosition() const {
	int* arr = new int[3]; 
	arr[0] = x; 
	arr[1] = y;
	arr[2] = z; 
	return arr; 
}

void Space::rotateAroundX(int& theta) {
	y = (int)(y * cos(theta)) - (int)(z * sin(theta)); 
	z = (int)(y * sin(theta)) + (int)(z * cos(theta));  
}

void Space::rotateAroundY(int& theta) {
	x = (int)(x * cos(theta)) + (int)(z * sin(theta)); 
	z = (int)(-x * sin(theta)) + (int)(z * cos(theta)); 
}

void Space::rotateAroundZ(int& theta) {
	x = (int)(x * cos(theta)) - (int)(y * sin(theta)); 
	y = (int)(x * sin(theta)) + (int)(y * cos(theta)); 
}

void Space::moveAlongX(int& num) {
	x += num; 
}

void Space::moveAlongY(int& num) {
	y += num; 
}

void Space::moveAlongZ(int& num) {
	z += num; 
}