#include<iostream>
#include<vector>
using namespace std;

int R, C, lookup[100][100], M, F = -1, A, sharks[10000];
class Shark {
public:
	int r, c, s, d, z, idx, eat;
	Shark(int rr, int cc, int ss, int dd, int zz, int idx, int eat) { 
		r = rr; c = cc; s = ss; d = dd; z = zz; 
		idx = idx;
		eat = eat;
	}
	void move() {
		int dr = 0, dc = 0;
		if (d == 1) { dr = -1; }
		else if (d == 2) { dr = 1; }
		else if (d == 3) { dc = 1; }
		else if (d == 4) { dc = -1; }	
		for (int i = 0 ; i < s; i++) {
			if (r == 0 || r == R - 1 || c == 0 || c == C - 1) { dc *= -1; dr *= -1; }
			r += dr; c += dc;
			if (lookup[r][c] != -1) {
				eat = sharks[lookup[r][c]] > 
		}
	} 
};

void print_lookup() {
	for (int i = 0 ; i < R; i++) {
		for (int j = 0 ; j < C; j++) {
			cout << lookup[i][j] << " ";	
		}
		cout << endl;
	}
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
		lookup[tr-1][tc-1] = i;
		sharks[i] = new Shark(tr, tc, ts, td, tz);
	}
	print_lookup();
}

void fisher_move() {
	F += 1;
}

void fisher_catch() {
	for (int i = 0 ; i < R ; i++){
		if(lookup[F][i] >= 0){
			A += sharks[lookup[F][i]]->s; 
			break;
		}
	}
}

void shark_move() {
	for (int i = 0 ; i < M ; i++) {
		if (sharks[i]->size() != -1){
			sharks[i]->move();
		}
	}	
} 

void shark_eat() {
	for (int i = 0 ; i < 
}

int main() {
	read_input();
	for (int i = 0 ; i < C; i++) {
		fisher_move();
		fisher_catch();
	}	
	cout << A << endl;
	return 0;
}

