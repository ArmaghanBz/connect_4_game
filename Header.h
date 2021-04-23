#include <iostream>
using namespace std;

class game
{
public:
	int arr[7][7];
	int board(int arr[7][7], int a, int b);
	int check(int arr[7][7], int t, int j);
	int draw(int arr[7][7], int k);
};

