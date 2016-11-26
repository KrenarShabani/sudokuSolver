// SudokuWrapper.h

#pragma once
#include "SudokuHandeler.h"
#include "SudokuHandeler.cpp"
#include "sudoku.cpp"
#include "sudoku.h"
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
