#include <iostream>
#include <vector>

#define R 0
#define U 1
#define L 2
#define D 3

using namespace std;

int N, x, y, d, g;
int arr[101][101] = { 0, };
vector<pair<int, int> > dragon[20];
int gen[20];
pair<int, int> e[20];

void debug() {
  for (int i = 0 ; i < N; i++) {
    for (int j = 0 ; j < dragon[i].size(); j++) {
      cout << "(" << dragon[i].at(j).first << ", " << dragon[i].at(j).second << ") ";
    }
    cout << endl;
  }
}

void debug_arr() {
  for (int i = 0 ; i < 101; i++) {
    for (int j = 0 ; j < 101; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

pair<int, int> rotate(int x, int y, int ox, int oy) {
  int dx = ox - x;
  int dy = oy - y;
  return make_pair(ox + dy, oy - dx);
}

void grow(int i) {
  int size = dragon[i].size();
  pair<int, int> p;
  int ox = e[i].first;
  int oy = e[i].second;
  //cout << "origin " << ox << ", " << oy << endl;
  for (int j = size - 2; j >= 0; j--) {
    p = rotate(dragon[i].at(j).first, dragon[i].at(j).second, ox, oy);
    if (100 < p.first ||  p.first < 0 || 100 < p.second || p.second < 0)
      break;
    //cout << "target " << dragon[i].at(j).first << ", " << dragon[i].at(j).second << " new " << p.first << ", " << p.second << endl;
    dragon[i].push_back(p);
    arr[p.second][p.first] = 1;
    e[i] = p;
  }

  //debug_arr();
}

int count() {
  int count = 0;
  for (int i = 0 ; i < 100; i++){
    for (int j = 0; j < 100; j++) {
      if (arr[i][j] == 1 && arr[i+1][j] == 1 
          && arr[i][j+1] == 1 && arr[i+1][j+1] == 1) 
        count++;
    }
  }
  return count;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> d >> g; 

    // x, y 
    dragon[i].push_back(make_pair(x, y));

    // d 
    pair<int, int> p;
    if (d == R && x < 100)
      p = make_pair(x + 1, y);
    else if (d == L && 0 < x )
      p = make_pair(x - 1, y);
    else if (d == U && 0 < y)
      p = make_pair(x, y - 1);
    else if (d == D && y < 100)
      p = make_pair(x, y + 1);
    dragon[i].push_back(p);

    // g
    gen[i] = g;  

    // e
    e[i] = p;

    // arr
    arr[y][x] = 1;
    arr[p.second][p.first] = 1;
  }
  //debug_arr();

  // rotate
  pair<int, int> p = rotate(3, 3, 0, 0);
  //cout << p.first << ", " << p.second << endl;
  
  for (int i = 0; i < N; i++){
    for (g = 1; g <= 10; g++) {
      if (g <= gen[i]) {
        //cout << endl << i << "용" << g << "세대" << endl;
        grow(i); 
      }
    }
  }

  cout << count() << endl;

  return 0;
}
