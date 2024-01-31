#include "Quad.h"
#include <iostream>
#include <cmath>

Quad::Quad() {
	a = 0.0f; 
	b = 0.0f; 
	c = 0.0f; 
}

void Quad::putCeoff(float a, float b, float c) {
	this->a = a; 
	this->b = b;
	this->c = c; 
}

float Quad::returnA() const {
	return a; 
}

float Quad::returnB() const {
	return b; 
}

float Quad::returnC() const {
	return c; 
}

float Quad::evaluate(float& mult) {
	float answer; 
	answer = (a * sqrt(mult)) + (b * mult) + c; 
	return answer; 
}

void Quad::display() {
	std::cout << "\nCurrent Quadratic equation -> ";
	std::cout << a << "x^2 + " << b << "x + " << c << std::endl; 
}

Quad operator +(const Quad& q1, const Quad& q2) {
	Quad add; 
	add.a = q1.a + q2.a; 
	add.b = q1.b + q2.b;
	add.c = q1.c + q2.c; 
	return add; 
}

Quad operator * (const Quad& q, double& num) {
	Quad mult; 
	mult.a = q.a * (float)num; 
	mult.b = q.b * (float)num;
	mult.c = q.c * (float)num; 
	return mult; 
}