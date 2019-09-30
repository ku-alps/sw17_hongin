#include <iostream>
using namespace std;
int main()
{
	int N, arr[1000001], a, b, c;
	cin >> N;
	arr[1] = 0;
	
		
	for (int i = 2; i <= N; i++)
	{
		a = 1000000, b = 1000000, c = 1000000;
		if (i % 3 == 0) 
			a = arr[i/3] + 1;
		if (i % 2 == 0)
			b = arr[i/2] + 1;
		c = arr[i - 1] + 1;
		arr[i] = a < b ? (c < a ? c : a) : (c < b ? c : b);
		//cout << i << " : " << arr[i] << " (" << a << ", " << b << ", "<< c << ")" << endl;
	}
			
	cout << arr[N];
	return 0;
}
