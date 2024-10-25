#include<iostream>
using namespace std;
int board[ 3 ][3] = { 0 },player=1,who;
int row, col;
bool winner = false;
void printboard(int b[][3], int row)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == 1)
			{
				cout << " X ";
			}
			else if (b[i][j] == 2)
			{
				cout << " O  ";
			}
			else
				cout << " _ ";
		}
		cout << endl;
	}

}
void updateboard(int b[][3], int row, int col, int num)
{
	b[row][col] = num;

}
bool checkWinner(int b[][3],int &who)
{
	/*if (b[0][0] == b[0][1] && b[0][0] == b[0][2] && b[0][0] != 0)
	{
		who = b[0][0];
		return true;
	}
	else if (b[1][0] == b[1][1] && b[1][0] == b[1][2] && b[1][0] != 0)
	{
		who = b[1][1];
		return true;
	}
	return false;
	*/
	for (int r = 0; r < 3; r++)
	{
		if (b[r][0] == b[r][1] && b[r][0] == b[r][2] && b[r][0] != 0)
		{
			who = b[r][0];
			return true;
		}
		
	}
	for (int c = 0; c < 3; c++)
	{
		if (b[0][c] == b[1][c] && b[1][c] == b[2][c] && b[0][c] != 0)
		{
			who=b[0][c];
			return true;
		}
	}
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != 0)
	{
		who = b[0][0];
		return true;
	}
	else if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != 0 )
	{
		who = b[0][2];
		return true;
	}
	return false;




}
void calculate(int b[][3], int &r, int &c, int p)
{
	if (b[1][1] == 0)
	{
		r = 1;
		c = 1;


	}
	else if (b[0][0] == 0)
	{
		r = 0; c = 0;
	}
	else if (b[0][2] == 0)
	{
		r = 0; c = 2;
	}
	else if (b[2][0] == 0)
	{
		r = 2; c = 0;
	}
	else if (b[2][2] == 0)
	{
		r = 2; c = 2;
	}

}
int main()
{
	printboard(board, 3);
	for (int i = 0; i < 9&&winner==false; i++)
	{
		if (player == 1)
		{
			cin >> row >> col;
			while (board[row][col] != 0||row>2||col>2)
			{
				cout << "invalid:Enter again" << endl;
				cin >> row >> col;
			}
			//calculate(board, row, col, 1);
			
			updateboard(board, row, col, 1);
			player = 2;
		}
		else
		{
			cin >> row >> col;
			while (board[row][col] != 0 || row > 2 || col > 2)
			{
				cout << "invalid:Enter again" << endl;
				cin >> row >> col;
			}
			updateboard(board, row, col, 2);
			player = 1;
		}
		cout << endl;
		printboard(board, 3);
		winner = checkWinner(board, who);
	}
	if (winner)
	{
		cout << "winner is " << who << endl;
	}
	system("Pause");
}