#include<iostream>
#include<vector>
using namespace std;

int R, C, lookup[100][100], M, F = -1, A = 0;
class Shark {
public:
	int r, c, s, d, z, dc, dr;
	Shark(int rr, int cc, int ss, int dd, int zz) { 
		r = rr; c = cc; s = ss; d = dd; z = zz; 
		dr = 0, dc = 0;
		if (d == 1) { dr = -1; }
		else if (d == 2) { dr = 1; }
		else if (d == 3) { dc = 1; }
		else if (d == 4) { dc = -1; }	
	}
	void move() {
//		cout << "moving from " << r << ", " << c << endl;
		for (int i = 0 ; i < s; i++) {
			if ( (r == 0 && dr == -1) || (r == R - 1 && dr == 1) )
				dr *= -1;
			if ( (c == 0 && dc ==-1) || (c == C - 1 && dc == 1) )
				dc *= -1; 
			r += dr; c += dc;
//			cout << r << ", " << c << endl;
		}
//		cout << "moved to " << r << ", " << c << endl;
	} 
};
Shark* sharks[10000];

void print_lookup() {
	for (int i = 0 ; i < R; i++) {
		for (int j = 0 ; j < C; j++) {
			cout << lookup[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_sharks() {
	for (int i = 0 ; i < M; i++) {
		cout << sharks[i]->r << " " << sharks[i]->c << " " << sharks[i]->s << " " <<
		  sharks[i]->d << " " << sharks[i]-> z << " "  << endl;
	}
	cout << endl;
}

void init_lookup() {
	for (int i = 0 ; i < R ; i++) {
		for (int j = 0 ; j < C ; j++) {
			lookup[i][j] = -1;
		}
	}
}

void read_input() {
	cin >> R >> C >> M;
	init_lookup();
	int tr, tc, ts, td, tz;
	for (int i = 0 ; i < M ; i++) {
		cin >> tr >> tc >> ts >> td >> tz;
		tr -= 1; tc -= 1;
		lookup[tr][tc] = i;
		sharks[i] = new Shark(tr, tc, ts, td, tz);
	}
//	print_lookup();
//	print_sharks();
}

void fisher_move() {
	F += 1;
}

void fisher_catch() {
//	print_sharks();
	for (int i = 0 ; i < R ; i++){
		if(lookup[i][F] >= 0){
//			cout << "A : " << A << " + " << sharks[lookup[i][F]]->z << endl;
			A += sharks[lookup[i][F]]->z; 
			sharks[lookup[i][F]]->z = -1;
			break;
		}
	}
}

void shark_move() {
	for (int i = 0 ; i < M ; i++) {
		if (sharks[i]->z == -1) continue;
		sharks[i]->move();
	}	
//	cout << "Moved" << endl;
//	print_sharks();
} 

void shark_eat() {
	init_lookup();	
	int r, c;
	for (int i = 0 ; i < M ; i++) {
		if (sharks[i]->z == -1) continue;
		r = sharks[i]->r;
		c = sharks[i]->c;
		//cout << r << " " << c << " "<< " : " << i << endl;
		if (lookup[r][c] == -1) {
			lookup[r][c] = i;
		} else {
			if (sharks[i]->z > sharks[lookup[r][c]]->z ){
				sharks[lookup[r][c]]->z = -1;
				lookup[r][c] = i;
//				cout << "EAT " << endl;
			} else {
				sharks[i]->z = -1;
			}
		}
	}
//	cout << "printing lookup" << endl;
//	print_lookup();
//	print_sharks();
}

int main() {
	read_input();
	for (int i = 0 ; i < C; i++) {
		fisher_move();
		fisher_catch();
		shark_move();
		shark_eat();
	}	
	cout << A << endl;
	return 0;
}

