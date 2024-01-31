#include "Quad.h"
#include <iostream>

int main() {
	Quad q1; 
	Quad q2; 
	float value; 
	q1.display(); 
	q2.display(); 

	std::cout << "\nAssigned object values...." << std::endl;
	q1.putCeoff(5, 5, 6); 
	q1.display(); 
	q2.putCeoff(9, 3, 2); 
	q2.display(); 

	std::cout << "\nValue for solving quadratics ->";
	std::cin >> value; 
	std::cout << "\nfirst quadratic solution = " << q1.evaluate(value) << std::endl;
	std::cout << "second quadratic solution = " << q2.evaluate(value) << std::endl;
	
	std::cout << "\nadd quadratics together......" << std::endl;
	Quad q3 = { q1 + q2 }; 
	std::cout << "\nNew Quadratic -> ";
	q3.display(); 
	std::cout << "\nNew quadratic solved using last initialized value\n";
	std::cout << " New quadratic = " << q3.evaluate(value) << std::endl;

	std::cout << "\nFirst quadratic coefficiants multiplied by value....." << std::endl;
	double val = double(value); 
	Quad q4 = { q1 * val };
	q4.display(); 

	return EXIT_SUCCESS; 
}
