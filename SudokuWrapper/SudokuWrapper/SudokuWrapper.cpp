// This is the main DLL file.
#pragma once
#include "stdafx.h"
#include "SudokuWrapper.h"
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\SudokuHandeler.h"
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\SudokuHandeler.cpp"
#include "C:\Users\krenar1\Documents\Visual Studio 2013\Projects\SudokuCore\SudokuCore\drivercpp.cpp"

SudokuWrapper::SudokuWrapperClass::SudokuWrapperClass()
{
	pSH = new sudokuHandeler();
	lol = gcnew array<int,2>(9,9);
}
void SudokuWrapper::SudokuWrapperClass::addRow(int* ptr, int index)
{
	pSH->addRow(ptr,index);
}
bool SudokuWrapper::SudokuWrapperClass::process()
{
	sudoku test[9][9];
	sudoku*** pointers = pSH->getSud();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			test[i][j] = *pointers[i][j];
		}
	}


	//if (pSH->processSudoku(test, 0, 0))
	if (processSudoku(test,0,0))
	{
		int set[9][9];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				lol[i, j] = test[i][j].getNum();
			}
		}




		return true;
	}
	else
		return false;
	

}
int* SudokuWrapper::SudokuWrapperClass::getGrid(int index)
{
	sub = new int[9];
	for (int i = 0; i < 9; i++)
	{
		sub[i] = lol[i,index];
	}
	return sub;
}

void SudokuWrapper::SudokuWrapperClass::setGrid(int*** arr)
{

	pSH->GetInput(arr);

}