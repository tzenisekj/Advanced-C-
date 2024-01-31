#ifndef QUAD_H
#define QUAD_H

class Quad {
public:
	Quad(); 
	void putCeoff(float, float, float); 
	float returnA() const; 
	float returnB() const; 
	float returnC() const; 
	float evaluate(float&); 
	void display(); 

	friend Quad operator +(const Quad&, const Quad&); 
	friend Quad operator *(const Quad&, double&); 
private:
	float a, b, c; 
};

#endif