// KRENAR SHABANI 
#pragma once
#include "sudoku.h"
#include "SudokuHandeler.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool processSudoku(sudoku nums[][9], int x, int y);
bool check(sudoku nums[][9], int x, int y, int theNum);
void Write(ofstream& file, sudoku nums[][9]);
void Read(ifstream& input, sudoku nums[][9]);
void printn(sudoku nums[][9]);
//int count = 0;
int main()
{
	//ifstream input("C:\\Users\\krenar1\\Documents\\GitHub\\sudokugui\\sudokuSolver\\input.txt");
	//ifstream input("INPUT TXT HERE");
	static const int empty = 0;
	//sudoku sud[9][9];
	sudokuHandeler sud;
	//Read(input, sud.sud);

	if (processSudoku(sud.sud, 0, 0))
	{
		cout << "it works!!!" << endl;
	}
	else
		cout << "failure!!" << endl;
	//cout << "ProcessSudoku was called " << count << " times!" << endl;   
	//input.close();

	//ofstream output("INSERT OUTPUT TXT HERE");
	//Write(output, sud.sud);
	//output.close();

	//sud.GetOutput(1);
	cin.get();
	return 0;
}







