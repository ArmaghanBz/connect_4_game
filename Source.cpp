#include "Header.h"
int game::board(int arr[7][7], int a, int b)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return arr[7][7];
}
int game::check(int arr[7][7], int t, int j)
{
	for (int i = 0; i < 7; i++)
	{
		for (int x = 0; x < 7; x++)
		{
			if (arr[i][x] == j && arr[i][x + 1] == j)
			{
				if (arr[i][x + 1] == j && arr[i][x + 2] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i][x] == j)
			{
				if (arr[i][x] == j && arr[i][x - 2] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i - 1][x] == j)
			{
				if (arr[i - 1][x] == j && arr[i - 2][x] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i + 1][x] == j)
			{
				if (arr[i + 1][x] == j && arr[i + 2][x] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i - 1][x - 1] == j)
			{
				if (arr[i - 1][x - 1] == j && arr[i - 2][x - 2] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i - 1][x + 1] == j)
			{
				if (arr[i - 1][x + 1] == j && arr[i - 2][+2] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i + 1][x - 1] == j)
			{
				if (arr[i + 1][x - 1] == j && arr[i + 2][x - 2] == j)
					t = 1;
			}
			else if (arr[i][x] == j && arr[i + 1][x + 1] == j)
			{
				if (arr[i + 1][x + 1] == j && arr[i + 2][x + 2] == j)
					t = 1;
			}
		}
	}
	return t;
}
int game::draw(int arr[7][7], int k)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[i][j] == 0)
			{
				k = 1;
			}
		}
	}
	return k;
}
int main()
{
	game g;

	cout << "\t\t\tLET'S BEGIN !!  " << endl << endl;;
	//for making of board
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			g.arr[i][j] = 0;
			cout << g.arr[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
	while (true)
	{
		int a, b;
		int j = 1;
		int count = 0;
		int w;
		int k = 0, d;
		cout << "Player 1: your turn." << endl;

	error1:
		cin >> a;
		cin >> b;
		//this condition is to check whether is any move before
		if (g.arr[a][b] == 1 || g.arr[a][b] == 2)
		{
			cout << "ERROR!! THERE IS ALREADY A NUMBER";
			goto error1;
		}
		if (g.arr[a][b] == 0)
		{
			g.arr[a][b] = 1;
			g.board(g.arr, a, b);
			j = 1;
			g.check(g.arr, count, j);

			w = g.check(g.arr, count, j);
			if (w == 1)
			{
				cout << "player1... YOU WIN !!";
				break;
			}
			int k = 0, d;
			g.draw(g.arr, k);
			d = g.draw(g.arr, k);
			if (d == 0)
			{
				cout << "the match has drawn";
				break;
			}


		}

		cout << "player 2, its you turn now:" << endl;
	error2:
		cin >> a;
		cin >> b;
		//this condition is to check whether is any move before
		if (g.arr[a][b] == 1 || g.arr[a][b] == 2)
		{
			cout << "ERROR!! THERE IS ALREADY A NUMBER";
			goto error2;
		}
		if (g.arr[a][b] == 0)
		{
			g.arr[a][b] = 2;
			g.board(g.arr, a, b);
			j = 2;
			g.check(g.arr, count, j);
			w = g.check(g.arr, count, j);
			if (w == 1)
			{
				cout << "player2... YOU WIN !!";
				break;
			}
			g.draw(g.arr, k);
			d = g.draw(g.arr, k);
			if (d == 0)
			{
				cout << "the match has drawn";
				break;
			}


		}
	}
	return 0;
}


