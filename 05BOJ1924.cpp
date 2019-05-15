#include <iostream>
#include <string>
using namespace std;


int main(){
	int month[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int x, y;
	cin >> x >> y;
	int daysinyear = 0;
	for (int i = 0 ; i < x -1; i++)
		daysinyear += month[i];
	daysinyear += y;
	string weekdays[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	cout << weekdays[daysinyear % 7];
}
