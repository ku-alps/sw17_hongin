#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int C, K;
	cin >> C >> K;
	K = pow(10, K);
	cout << (C % K >= K/2 ? (C/K + 1)*K : (C/K) *K); 
}
