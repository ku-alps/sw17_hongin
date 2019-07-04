#include <iostream>
using namespace std;
int main()
{
	int k, *S;
	cin >> k;
	while (k != 0)
	{
		S = new int[k];
		for (int i = 0 ; i < k; i++)
			cin >> S[i];
		for (int i = 0 ; i < k; i++)
			cout << S[i];
		delete[] S;	
		cin >> k;
	}	
	return 0;
}
