#include <fstream> // included for file work
#include <iostream>
#include <cstdlib>
#include <string>
#include "Stack2.h"
using namespace main_savitch_7B; 

// function prototypes
void validate_argc(int argc, int right, const char usage[]);
void open_for_read(std::ifstream& f, const char file_name[]); 
void process_file(std::ifstream& f, const char file_name[]);
bool is_more(std::istream& f); 

//global variables
std::ifstream IN_FILE; // opening file to read
size_t ARGC_NUM = 2; 



// MAIN FUNCTION
int main(int argc, char* argv[]) {
	validate_argc(argc, ARGC_NUM, "usage: calc input_file"); 
	process_file(IN_FILE, argv[1]); 

	return EXIT_SUCCESS; 
}

// validates the argc for program is equal to the necessary number for program to run properly 
void validate_argc(int argc, int right, const char usage[]) {
	if (argc != right) {
		std::cerr << usage << std::endl;
		exit(-2); 
	}
}

// opens a file and makes sure it opens properly 
void open_for_read(std::ifstream& f, const char file_name[]) {
	f.open(file_name); 
	if (f.fail()) {
		std::cerr << "Error! File unable to open!\nExiting program......." << std::endl;
		exit(-2); // halts and ends program with exit code (-2)
	}
}

// processes and reads the file put through 
void process_file(std::ifstream& f, const char file_name[]) {
	open_for_read(f, file_name);
	double answer; 

	while (is_more(f)) { 
		stack<double> sd; // holds double numbers
		double num; // for reading in
		double num_1, num_2; // storing out of stack
		char fill; // reading in operators
		bool valid = true; // holds valid expression 
		stack<char> operators; // holds operators for expression

		while (f.peek() != '\n') {
			if (valid) {
				if (isdigit(f.peek())) {
					f >> num;
					sd.push(num);
				}
				else if (f.peek() == '+' || f.peek() == '-' || f.peek() == '*' || f.peek() == '/') {
					f >> fill;
					operators.push(fill);
				}

				if (operators.size() == 1) {
					if (sd.size() < 2) {
						valid = false;
						break;
					}
					else {
						if (sd.top() == 0 && operators.top() == '/') {
							valid = false;
							break;
						}
						else {
							valid = true;
							num_2 = sd.top();
							sd.pop();
							num_1 = sd.top();
							sd.pop();
							fill = operators.top();
							operators.pop();

							switch (fill) {
							case '+':
								answer = num_1 + num_2;
								sd.push(answer);
								break;
							case '-':
								answer = num_1 - num_2;
								sd.push(answer);
								break;
							case '*':
								answer = num_1 * num_2;
								sd.push(answer);
								break;
							case '/':
								answer = num_1 / num_2;
								sd.push(answer);
								break;
							}
						}
					}
				}
			}
			else
				f.ignore(); 
		}
		if (sd.size() != 1 || !valid) {
			std::cout << "Answer = INVALID" << std::endl;
			std::cout << std::endl;
		}
		else {
			std::cout << "Answer = " << sd.top() << std::endl;
			std::cout << std::endl;
			sd.pop(); 
		}
	}

	f.close(); 
}

bool is_more(std::istream& f) {
	if (f && f.peek() != EOF)
		return true;
	else
		return false; 
}
