#include <string>
#ifndef BOOK_H
#define BOOK_H

class Book {
private:
	std::string Name; 
	std::string Author; 
	std::string Publication_Date;
	std::string ISBN;

	bool operator >(Book& i) const { return (Author < i.get_Author()); }

public:
	Book() {
		Name = "";
		Author = "";
		Publication_Date = "";
		ISBN = "";
	}

	Book(std::string Name, std::string Author, std::string Publication_Date, std::string ISBN) {
		this->Name; 
		this->Author; 
		this->Publication_Date;
		this->ISBN;
	}

	void set_Name(std::string Name) { this->Name; }
	std::string get_Name() const { return Name; }

	void set_Author(std::string Author) { this->Author; }
	std::string get_Author() const { return Author; }

	void set_Publication(int Date) { Publication_Date = Date; }
	std::string get_Publication() const { return Publication_Date; }

	void set_ISBN(std::string ISBN) { this->ISBN; }
	std::string get_ISBN() const { return ISBN; }
};
#endif
