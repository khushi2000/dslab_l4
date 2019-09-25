/**
* @file l4p3
* @this print all possible solution of Nqueen problem
* @author khushi
* @date 18-8-2019
*/ 
#include <iostream>
#include <cstring>
using namespace std;

long long int count=0;




// N x N chessboard
#define N 6

// Function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c)
{
	// return false if two queens share the same column
	for (int i = 0; i < r; i++)
		if (mat[i][c] == '1')
			return false;

	// return false if two queens share the same \ diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (mat[i][j] == '1')
			return false;

	// return false if two queens share the same / diagonal
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (mat[i][j] == '1')
			return false;

	return true;
}

void nQueen(char mat[][N], int r)
{
	// if N queens are placed successfully, print the solution
	if (r == N)
	{
		count++;
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		
		return;
	}

	// place Queen at every square in current row r
	// and recur for each valid movement	
	for (int i = 0; i < N; i++) 
	{
		// if no two queens threaten each other
		if (isSafe(mat, r, i)) 
		{
			// place queen on current square
			mat[r][i] = '1';

			// recur for next row
			nQueen(mat, r + 1);

			// backtrack and remove queen from current square
			mat[r][i] = '0';
		}
	}
}

int main()
{
	// mat[][] keeps track of position of Queens in current configuration
	
	char mat[N][N];

	// initalize mat[][] by '0'
	memset(mat, '0', sizeof mat);

	nQueen(mat, 0);

	cout<<"number of possible solutions = "<<count<<endl;

	return 0;
}
