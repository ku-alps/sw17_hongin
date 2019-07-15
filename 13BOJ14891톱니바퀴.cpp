#include <iostream>
#include <string>
#include <vector>
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

void chain_rotate(int arr[][8], int i, int dir) {
	cout << "Visiting " << i << endl;
	if (i == -1 || i == 4)
		return;

	if (dir == 1)
		clockwise(arr[i]);
	else if (dir == -1)
		anticlock(arr[i]);

	
	if (arr[i][2] != arr[i+1][6])
		chain_rotate(arr, i+1, (-1)*dir); 
	if (arr[i-1][6] != arr[i][2])
		chain_rotate(arr, i-1, (-1)*dir); 
}

int main() {
	int arr[4][8], K, gear, direction;
	string temp;
	for (int i = 0; i < 4; i++){
		cin >> temp;
		for (int j = 0 ; j < 8; j++) {
			arr[i][j] = (int)(temp[j] - '0');
		}	
	}

	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> gear >> direction;
		chain_rotate(arr, gear - 1, direction);
		for (int i = 0; i < 4; i++) {
			for (int j = 0 ; j < 8; j++)
				cout << arr[i][j] ;
			cout << endl ;
		}
	}
	return 0;
}
