// KRENAR SHABANI 
#include "stdafx.h"
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
	//ifstream input("C:\Users\krenar1\Documents\GitHub\sudokugui\sudokuSolver\input.txt");
	ifstream input("INPUT TXT HERE");
	static const int empty = 0;
	sudoku sud[9][9];
	Read(input, sud);

	if (processSudoku(sud, 0, 0))
	{
		cout << "it works!!!" << endl;
	}
	else
		cout << "failure!!" << endl;
	//cout << "ProcessSudoku was called " << count << " times!" << endl;   
	input.close();

	ofstream output("INSERT OUTPUT TXT HERE");
	Write(output, sud);
	output.close();
	cin.get();
	return 0;
}

bool processSudoku(sudoku nums[][9], int x, int y)
{
	//count++;
	printn(nums);
	if (nums[x][y].isInput())
	{
		cout << y << " " << x << " is a user number (" << nums[x][y].getNum() << ")" << endl << endl;
		if (x == 8 && y == 8) {
			printn(nums);
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

		if (check(nums, x, y, i) && !nums[x][y].isInput())
		{
			nums[x][y].setNum(i);
			cout << "setting " << y << " " << x << " to " << i << endl << endl;
			if (x == 8 && y == 8) {
				printn(nums); //sudoku has been completed!
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


bool check(sudoku nums[][9], int x, int y, int theNum)
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


void Write(ofstream& file, sudoku nums[][9])
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
void printn(sudoku nums[][9])
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


