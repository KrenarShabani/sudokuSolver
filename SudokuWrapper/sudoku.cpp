#pragma once
#include "sudoku.h"
using namespace std;

//constructors
sudoku::sudoku(bool user, int n) :
userInput(user),
num(n)
{}
sudoku::sudoku() :
userInput(false),
num(0)
{}
//getters 
int sudoku::getNum()
{
	return num;
}
bool sudoku::isInput()
{
	return userInput;
}
bool sudoku::isEmpty()
{
	return IsEmpty;
}
//setters
void sudoku::instantiate(bool isuser, int n)
{
	setNum(n);
	if (n == 0)
		isuser = false;
	else
		userInput = isuser;
}
void sudoku::setNum(int n)
{
	if (userInput)
	{
		cout << "this box is user inputed.(" << num << ") exiting" << endl;
		exit(0);
	}
	if (n == 0)
	{
		num = 0;
		IsEmpty = true;
		return;
	}
	if (n < 1 || n > 9)
	{
		cout << "illegal action. exiting" << n << endl;
		exit(0);
	}
	if (IsEmpty && n != 0)
		IsEmpty = false;
	num = n;
}
//overloading
