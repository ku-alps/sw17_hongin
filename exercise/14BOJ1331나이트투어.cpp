#include <iostream>
#include <cmath>
using namespace std;

int ir, ic, r, c, pr, pc, arr[6][6];
char temp[2];

bool valid(int r, int c){
	if ( 0 <= r && r <= 5)
		if ( 0 <= c && c <= 5)
			return true;
	return false;
}

bool dist(int r, int c, int pr, int pc) {
	if (abs(r - pr) + abs(c - pc) == 3)
		if (r != pr && c != pc)
			return true;
	return false;
}

bool ovrd(int r, int c) {
    if (arr[r][c] == 0){
        arr[r][c]++;
        return true;
    }
    return false;
}

int main(){
    for (int i = 0; i < 6; i++)
        for (int j = 0 ; j < 6; j++)
            arr[i][j] = 0;
    
	cin >> temp;
	r = (int) ('6' - temp[1]);
	c = (int) (temp[0] - 'A');
    ir = r;
    ic = c;

	if (valid(r, c) == false) {	cout << "Invalid" << endl; return 0;	}
	
	for (int i = 1 ; i < 36; i++) {
		pr = r; pc = c;
		cin >> temp;
		r = (int) ('6' - temp[1]);
		c = (int) (temp[0] - 'A');

		if (valid(r, c) == false) {	cout << "Invalid" << endl; return 0; }
		if (dist(r, c, pr, pc) == false) { cout << "Invalid" << endl; return 0; }
        if (ovrd(r, c) == false) { cout << "Invalid" << endl; return 0; }

	}
    
    if (dist(ir, ic, r, c) == false) { cout << "Invalid" << endl; return 0; }
	cout << "Valid" << endl;
	return 0;
}
