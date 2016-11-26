#pragma once
#include "sudoku.h"
#include "SudokuHandeler.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


sudokuHandeler::sudokuHandeler()
{
	
}

void sudokuHandeler::addRow(int* arr, int index)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] == 0)
			sud[i][index].instantiate(false,arr[i]);
		else
			sud[i][index].instantiate(true, arr[i]);
	}

}

bool sudokuHandeler::check(sudoku nums[][9], int x, int y, int theNum)
{
	int sectorx, sectory;
	if (x < 3)
		sectorx = 1;
	else if (x < 6)
		sectorx = 2;
	else
		sectorx = 3;
	if (y < 3)
		sectory = 1;
	else if (y < 6)
		sectory = 2;
	else
		sectory = 3;

	for (int i = 3; i > 0; i--) //this loop checks if there are any similar
	{                            //ints in it's sector (or box)
		for (int j = 3; j > 0; j--)
		{
			//     cout <<nums[(sectorx*3)-i][(sectory*3)-j].getNum();
			if (nums[(sectorx * 3) - i][(sectory * 3) - j].getNum() == theNum)
			{
				//       cout << endl<<endl;;
				return false;
			}
		}
		//cout << endl;
	}
	// cout << endl;
	//this loops checks if the int is facing a similar int in the x and y coordinates
	for (int i = 0; i < 9; i++)
	{
		//   cout << x;
		if (nums[x][i].getNum() == theNum)
			return false;
		// cout << nums[i][x].getNum() << endl;
	}
	for (int i = 0; i < 9; i++)
	{
		if (nums[i][y].getNum() == theNum)
			return false;
	}
	//    cout << endl;
	return true;
}

bool processSudoku(sudoku nums[][9], int x, int y)
{
	//count++;
	//sudokuHandeler::printn(nums);
	if (nums[x][y].isInput())
	{
		//cout << y << " " << x << " is a user number (" << nums[x][y].getNum() << ")" << endl << endl;
		if (x == 8 && y == 8) {
			sudokuHandeler::printn(nums);
			return true;
		}
		else if (x < 8)
		{
			if (processSudoku(nums, x + 1, y))
				return true;
			else
				return false;
		}
		else if (x == 8 && y < 8)
		{
			if (processSudoku(nums, 0, y + 1))
				return true;
			else
				return false;
		}
	}
	for (int i = 1; i < 10; i++)
	{

		if (sudokuHandeler::check(nums, x, y, i) && !nums[x][y].isInput())
		{
			nums[x][y].setNum(i);
			//cout << "setting " << y << " " << x << " to " << i << endl << endl;
			if (x == 8 && y == 8) {
				sudokuHandeler::printn(nums); //sudoku has been completed!
				return true;

			}
			else if (x < 8)
			{
				if (processSudoku(nums, x + 1, y))
					return true;
			}
			else if (x == 8 && y < 8)
			{
				if (processSudoku(nums, 0, y + 1))
					return true;
			}
		}
		if (!nums[x][y].isInput())
			nums[x][y].setNum(0);
	}
	return false;


}

void sudokuHandeler::printn(sudoku nums[][9])
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				cout << " ";
			}
			cout << nums[i][j].getNum();
		}
		cout << endl;
	}
	cout << endl;
}


void sudokuHandeler::Begin()
{

}

void sudokuHandeler::Write(ofstream& file, sudoku nums[][9])
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				cout << " ";
			}
			file << nums[i][j].getNum();
			cout << nums[i][j].getNum();
		}
		cout << endl;
		file << endl;
	}
}

void Read(ifstream& input, sudoku nums[][9])
{
	string temp;
	if (input.is_open())
	{
		for (int i = 0; i <9; i++)
		{
			if (input.eof())
			{
				cout << "end of file, this shouldnt happen" << endl;
				exit(0);
			}
			getline(input, temp);
			for (int j = 0; j < 9; j++)
			{
				if (temp[j] == ' ' || (temp[j] - 48) == 0)
				{
					nums[i][j].instantiate(false, 0);
				}
				else
				{
					nums[i][j].instantiate(true, temp[j] - 48);
				}
			}
		}
	}

}

sudoku*** sudokuHandeler::getSud()
{
	parray = new sudoku**[9];
	for (int i = 0; i < 9; i++)
	{
		parray[i] = new sudoku*[9];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			parray[i][j] = &sud[i][j];
		}
	}


	return parray;
}

void sudokuHandeler::GetInput(int*** pArray)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (*pArray[i][j] == 0)
			{
				sud[i][j].instantiate(false, *pArray[i][j]);
			}
			else
				sud[i][j].instantiate(true, *pArray[i][j]);
			
		}
	}

}
void sudokuHandeler::GetInput(int pArray[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (pArray[i][j] == 0)
			{
				sud[i][j].instantiate(false, pArray[i][j]);
			}
			else
				sud[i][j].instantiate(true, pArray[i][j]);

		}
	}

}

int* sudokuHandeler::GetOutput(int rowid)
{
	int** pointerarr = new int*[9];
	//pArray = new int**[9];
	for (int i = 0; i < 9; i++)
	{
		pointerarr[i] = new int[9];
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			pointerarr[i][j] = NULL;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			(pointerarr)[i][j] = sud[i][j].getNum();

		}
	}

	cout << "Printing pointer version" << endl;
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				cout << " ";
			}
			cout << pointerarr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return (pointerarr[rowid]);

}

