#include <iostream>
#include <cmath>
using namespace std;

void read_input(int &N, int **S);
void best_pick(int &you, int &notyou, int **S);

int main()
{
	int N, **S, start=0, link=0;
	read_input(N, S);
	cout << abs(start-link);	
	return 0;
}

void read_input(int &N, int **S)
{
	int i, j;
	cin >> N;
	S = new int*[N];
	for (i = 0 ; i < N; i++)
		S[i] = new int[N];
	for (i = 0 ; i < N; i++)
		for (j = 0 ; j < N; j++)
			cin >> S[i][j];
}
void best_pick(int &you, int &notyou, int **S){
}

