#include <iostream>
using namespace std;

int main(){
	int stairs;
	cin >> stairs;
	int arr[stairs], sum[stairs], hop1, hop2, hop3;
	bool cheat[stairs];

	cin >> arr[0];
	cheat[0] = false;
	
	cin >> arr[1];
	arr[1] += arr[0];
	cheat[1] = true;

	cin >> arr[2];
	hop1 = arr[0] + arr[2];
	hop2 = arr[1] + arr[2];
	arr[2] = hop1 > hop2 ? hop1 : hop2;
	cheat[2] = hop1 > hop2 ? false : true;

	cin >> arr[3];
	hop1 = arr[0] + arr[2] + arr[3];
	hop2 = arr[0] + arr[1] + arr[3];
	arr[3] = hop1 > hop2 ? hop1 : hop2;
	cheat[3] = hop1 > hop2 ? true : false;

	for (int i = 0 ; i < 4; i++)
		cout << arr[i] << endl;

	for(int i = 4 ; i < stairs; i++){
		cin >> arr[i];
		hop1 = 0, hop2 = 0, hop3 = 0;
		hop1 = arr[i-3] + arr[i-1] + arr[i];
		if(!cheat[i-3])
			hop2 = arr[i-3] + arr[i-2] + arr[i];
		hop3 = arr[i-4] + arr[i-2] + arr[i];
		cout << hop1 << ", " << hop2 << ", " << hop3 << endl;
		arr[i] += hop1 > hop2 ? (hop1 > hop3 ? arr[i-1] : arr[i-2]) : arr[i-2];
		cheat[i] = hop1 > hop2 ? (hop1 > hop3 ? true : false) : false;
	}
	cout << arr[stairs - 1];
	return 0;
}    
