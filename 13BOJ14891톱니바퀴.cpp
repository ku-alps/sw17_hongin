#include <iostream>
#include <string>
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

int main() {
	int arr[4][8];
	for (int i = 0; i < 4; i++){
		string temp;
		cin >> temp;
		for (int j = 0 ; j < 8; j++) {
			arr[i][j] = stoi(temp[j], );
			cout << arr[i][j] ;
		}	
		cout << endl;
	}
	
	return 0;
}
