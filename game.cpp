#include <iostream>
using namespace std;

void docs();

class game
{
	public:
		char arr[7][7];
		void board(char [7][7]);
		int check(char [7][7], int);
		int draw(char [7][7]);
};

int main()
{
	int a,b;
	game g;

	docs();
	for (int i=0; i<7; i++) {
		cout << "\t";
		for (int j=0; j<7; j++) {
			g.arr[i][j] = '*'; //Initialize the whole Board
			cout << g.arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	while (true) {	
		cout << "Player 1's Turn: ";
	error1:
		cin >> a >> b;
		
		if (g.arr[a][b] == '*') {
			
			g.arr[a][b] = 'X';
			g.board(g.arr);
			
			if (g.check(g.arr, 'X') == true) { 
				cout << "Player 1 Won! \n\n";
				break;
			}
			
			if (g.draw(g.arr) == true) {
				cout << "Its a Draw! \n\n";
				break;
			}
		}
		else {
			cout << "Its already Occupied, Pick Somewhere else: ";
			goto error1;
		}
		

		cout << "Player 2's Turn: ";
	error2:
		cin >> a >> b;
		
		if (g.arr[a][b] == '*') {
			g.arr[a][b] = 'O';
			g.board(g.arr);
			
			if (g.check(g.arr, 'O') == true) { 
				cout << "Player 2 Won! \n\n";
				break;
			}
			
			if (g.draw(g.arr) == true) {
				cout << "Its a Draw! \n\n";
				break;
			}
		}
		else {
			cout << "Its already Occupied, Pick Somewhere else: ";
			goto error2;
		}
	}
	
	return 0;
}

void docs() 		
{
	cout << endl
		<< "Welcome to the Connect-4 Board-Game. A Two-Player Turn-based Game. \n"
		<< " The Player 1 is assigned 'X'. \n"
		<< " The Player 2 is assigned 'O'. \n"
		<< endl;

	cout << "Pick the Specified Place according to the Index of the Row and Column. \n"
		<< "The First Player to Occupy any of the Three consecutive Places, would Win. \n"
		<< "You can Occupy either Horizontally, Vertically, or Diagonally. \n" 
		<< "The Override is not Allowed. \n"
		<< endl;
}		

void game::board(char arr[7][7])
{
	cout << endl;
	for (int i=0; i<7; i++) {
		cout << "\t";
		for (int j=0; j<7; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
}

int game::check(char arr[7][7], int p)
{
	for (int i=0; i<7; i++) {
		
		for (int j=0; j<7; j++) {
			
			if (arr[i][j] == p && arr[i][j+1] == p && arr[i][j+2] == p && arr[i][j+3] == p)
				return true; //Horizonatlly
			else if (arr[i][j] == p && arr[i + 1][j] == p && arr[i + 2][j] == p && arr[i + 3][j] == p)
				return true; //Vertically
			else if (arr[i][j] == p && arr[i + 1][j + 1] == p && arr[i + 2][j + 2] == p && arr[i + 3][j + 3] == p)
				return true; //Diagonally-Right
			else if (arr[i][j] == p && arr[i + 1][j - 1] == p && arr[i + 2][j - 2] == p && arr[i + 3][j - 3] == p)
				return true; //Diagonally-Left
		}
	}
	return false;
}

int game::draw(char arr[7][7])
{
	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			if (arr[i][j] == '*')
				return false;
		}
	}	
	return true;
}
