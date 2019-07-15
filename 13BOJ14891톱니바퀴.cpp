#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void clockwise(int *arr) {
	int temp = arr[7];
	arr[7] = arr[6];
	arr[6] = arr[5];
	arr[5] = arr[4];
	arr[4] = arr[3];
	arr[3] = arr[2];
	arr[2] = arr[1];
	arr[1] = arr[0];
	arr[0] = temp; 
}

void anticlock(int *arr) {
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = arr[2];
	arr[2] = arr[3];
	arr[3] = arr[4];
	arr[4] = arr[5];
	arr[5] = arr[6];
	arr[6] = arr[7];
	arr[7] = temp; 
}

void connected(int arr[][8], int i, int dir, int *wise) {
	if (i == -1 || i == 4)
		return;
	wise[i] = dir;
	if (wise[i+1] == 0 && arr[i][2] != arr[i+1][6])
		connected(arr, i+1, (-1)*dir, wise); 
	if (wise[i-1] == 0 && arr[i-1][2] != arr[i][6])
		connected(arr, i-1, (-1)*dir, wise); 
}

void rotate(int arr[][8], int dir[4]) {
	for (int i = 0 ; i < 4; i++){
		if (dir[i] == 1)
			clockwise(arr[i]);
		else if (dir[i] == -1)
			anticlock(arr[i]);
	}
}

int main() {
	int arr[4][8], K, gear, direction, *wise;
	string temp;
	wise = new int[4];
	for (int i = 0; i < 4; i++){
		cin >> temp;
		for (int j = 0 ; j < 8; j++) {
			arr[i][j] = (int)(temp[j] - '0');
		}	
	}

	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> gear >> direction;
		for (int i = 0; i < 4; i++)
			wise[i] = 0;
		connected(arr, gear - 1, direction, wise);
		rotate(arr, wise); 
	}
	int answer = 0;
	for (int i = 0 ; i < 4; i++)
		if (arr[i][0] == 1)
			answer += pow(2, i);
	cout << answer << endl;
	delete wise;
	return 0;
}
