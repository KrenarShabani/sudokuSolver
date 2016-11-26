// SudokuWrapper.h

#pragma once
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\SudokuHandeler.h"
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\SudokuHandeler.cpp"
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\sudoku.cpp"
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\sudoku.h"
using namespace System;

namespace SudokuWrapper {

	public ref class SudokuWrapperClass
	{
	public:
		array<int,2> ^lol;
		int* sub;
		SudokuWrapperClass();
		void addRow(int* ptr, int index);
		bool process();
		int * getGrid(int index);
		void setGrid(int*** parr);
	private:
		sudokuHandeler* pSH;
	};
}
