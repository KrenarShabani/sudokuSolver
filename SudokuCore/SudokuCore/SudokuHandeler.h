#pragma once
#include "sudoku.h"

class sudokuHandeler
{
private: 
	sudoku*** parray ;
	int*** pArray;

public:
	static bool check(sudoku nums[][9], int x, int y, int theNum);
	bool processSudoku(sudoku nums[][9], int x, int y);
	static void printn(sudoku nums[][9]);
	void Begin();
	static void Read(ifstream& input, sudoku nums[][9]);

	void Write(ofstream& file, sudoku nums[][9]);
	sudokuHandeler();
	sudoku*** getSud();
	void addRow(int* arr, int index);
	sudoku sud[9][9];
	void GetInput(int*** pArray);
	void GetInput(int pArray[][9]);
	int* GetOutput(int rowid);
};