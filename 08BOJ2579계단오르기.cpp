#include <iostream>
using namespace std;

bool tripple(int* cheat)
{
	if(*(cheat)==1 && *(cheat-1)==1)
		return true;
	else
		return false;
}
int main(){
	int stairs;
	cin >> stairs;
	int arr[stairs], sum[stairs], cheat[stairs], hop1, hop2, hop3;

	cin >> arr[0];
	sum[0] = arr[0];
	cheat[0] = 1;
	
	cin >> arr[1];
	sum[1] = arr[0] + arr[1];
	cheat[1] = 1;

	cin >> arr[2];
	hop1 = arr[0] + arr[2];
	hop2 = arr[1] + arr[2];
	//arr[2] = hop1 > hop2 ? hop1 : hop2;
	cheat[2] = hop1 > hop2 ? 2 : 1;
	sum[2] = arr[2] + arr[2-cheat[2]];

	cin >> arr[3];
	hop1 = arr[0] + arr[2] + arr[3];
	hop2 = arr[0] + arr[1] + arr[3];
	hop3 = arr[1] + arr[2];
	cheat[3] = hop1 > hop2 ? (hop1 > hop3 ? 1 : 2) : (hop2  > hop3 ? 2 : 2);
	sum[3] = arr[3] + sum[3-cheat[3]];

//	for (int i = 0 ; i < 4; i++)
		//cout << sum[i] << " (" << cheat[i] << ")" << endl;

	for(int i = 4 ; i < stairs; i++){
		cin >> arr[i];
		hop1 = 0, hop2 = 0, hop3 = 0;
		hop1 = arr[i-3] + arr[i-1] + arr[i];
		if(!tripple(cheat + i - 3))
			hop2 = arr[i-3] + arr[i-2] + arr[i];
		hop3 = arr[i-4] + arr[i-2] + arr[i];
		//cout << hop1 << ", " << hop2 << ", " << hop3 << endl;
		//arr[i] += hop1 > hop2 ? (hop1 > hop3 ? arr[i-1] : arr[i-2]) : arr[i-2];
		cheat[i] = hop1 > hop2 ? (hop1 > hop3 ? 1 : 2) : 2;
		sum[i] = arr[i] + sum[i-cheat[i]];
		//cout << sum[i] << " (" << cheat[i] << ")" << endl;
	}
	cout << sum[stairs - 1];
	return 0;
}    
