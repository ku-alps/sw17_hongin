#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

char map[8][8];
pair<int, int> o;
vector<pair<int, int> >visited;
int x[9] = { 0, -1, 0, 1, 1, 1, 0, -1, -1 };
int y[9] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };

void print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void fall() {
	for (int i = 7; i >= 1; i--) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
	for (int j = 0; j < 8; j++) {
		map[0][j] = '.';
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	// bfs 
	queue<pair<int, int> > q;
	queue<int> d;
	q.push(make_pair(0, 7));
	d.push(0);

	int round = 0;
	pair<int, int> t;
	int h;
	int c, r;

	while (!q.empty()) {
		// move
		t = q.front();
		h = d.front();
		q.pop();
		d.pop();

		if (round == 7) {
			cout << 1 << endl;
			return 0;
		}
		if (t.first == 7 && t.second == 0) {
			cout << 1 << endl;
			return 0;
		}

		if (h > round) {
			round++;
			fall();
			if (map[t.second][t.first] == '#')
				continue;
		}

		//print();
		//cout << t.first << ", " << t.second << " (depth " << h <<")"<< endl;

		for (int i = 0; i < 9; i++) {
			c = t.first + x[i];
			r = t.second + y[i];
			if (0 <= c && c <= 7 && 0 <= r && r <= 7) {
				if (map[r][c] != '#' && 0 < r && map[r - 1][c] != '#') {
					q.push(make_pair(c, r));
					d.push(h + 1);
				}
			}
		}
	}

	cout << '0' << endl;
	return 0;
}
