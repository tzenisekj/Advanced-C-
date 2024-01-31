#ifndef SPACE_H
#define SPACE_H

class Space {
public:
	Space(); 
	Space(int&, int&, int&); 
	void setPosition(int&, int&, int&);

	// getter
	int * getPosition() const;


	void rotateAroundX(int&); 
	void rotateAroundY(int&); 
	void rotateAroundZ(int&); 
	void moveAlongX(int&); 
	void moveAlongY(int&); 
	void moveAlongZ(int&); 

private:
	int x, y, z; 
};
#endif