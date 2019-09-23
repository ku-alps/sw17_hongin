#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

char map[8][8];
pair<int, int> o;
vector<pair<int, int> >visited;
int x[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int y[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};

void print() {
  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j < 8; j++) {
      printf("%c", map[i][j]);
    }
  }
  cout << endl;
}

void fall() {
  for (int i = 7; i >= 1; i--) {
    for (int j = 0 ; j < 8; j++) {
        map[i][j] = map[i-1][j];
    }
  }
  for (int j = 0 ; j < 8; j++) {
    map[0][j] = '.';
  }
}

int main() {
  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j < 8; j++) {
      scanf("%c", &map[i][j]);
    }
  }

  // bfs 
  queue<pair<int, int> > q; 
  q.push(make_pair(0, 7));
  visited.push_back(make_pair(0, 7));

  while(!q.empty()) {
    // move
    pair<int, int> t = q.front();
    q.pop();
    if (t.first == 7 && t.second == 0){
      cout << 1 << endl;
      return 0;
    }

    cout << t.first << ", " << t.second << endl;

    int c, r;
    for (int i = 0 ; i < 9; i++ ){
      c = t.first + x[i];
      r = t.second + y[i];
      if ( 0<= c && c<= 7 && 0<=r && r <=7){
        if ( 0 < r && map[r-1][c] !='#') {
          if (find(visited.begin(), visited.end(), make_pair(c, r)) == visited.end()){
            q.push(make_pair(c, r));
            visited.push_back(make_pair(c, r));
          }
        }
      }
    }
    
    // fall 
    fall();
  }

  cout << '0' << endl;
  return 0;
}
