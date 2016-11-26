#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
using namespace std;

class sudoku
{
private:
	bool userInput = false;
	bool IsEmpty = false;
	int num;

public:
	//constructors
	sudoku(bool user, int n);
	sudoku();
	//getters 
	int getNum();
	bool isInput();
	bool isEmpty();
	//setters
	void instantiate(bool isuser, int n);
	void setNum(int n);
	//overloading
};

#endif
