#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

char arr[100][100];
int N, M;

void draw() {
  for (int i = 0 ; i < N ; i++){
    for (int j = 0 ; j < M ; j++) {
      cout << arr[i][j];
    }
    cout << "\n"; 
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector<pair<int, int> > wolves;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'W')
        wolves.push_back(make_pair(i, j));
    }
  }

  // bfs 
  queue<pair<int, int> > q;
  vector<pair<int, int> > visited;
  pair<int, int> wolf;
  int dr[4] = {0, -1, 0, 1}; // left, up, right, down
  int dc[4] = {-1, 0, 1, 0};

  // push
  for (int i = 0 ; i < wolves.size() ; i++){
    q.push(wolves.at(i));
    visited.push_back(wolves.at(i));
  }
  while(!q.empty()){
    wolf = q.front();
    q.pop();
    //cout << wolf.first << ", " << wolf.second << "\n";
  
    for (int i = 0 ; i < 4 ; i++) {
      int r = wolf.first + dr[i];
      int c = wolf.second + dc[i];
      pair<int, int> next = make_pair(r, c);
      if (arr[r][c] == '+') {
        while(true) {
          if (arr[r+dr[i]][c+dc[i]] == '#') break;
          r = r + dr[i]; c = c + dc[i];
          next = make_pair(r, c);
          if (arr[r][c] == '.') break;
        }
      }
      if (r < 0 || r > N)
        continue;
      if (c < 0 || c > M)
        continue;
      if (arr[r][c] == '#')
        continue;
      if (find(visited.begin(), visited.end(), next) != visited.end())
        continue;

      visited.push_back(next);
      q.push(next);
    }
  }

  for (int i = 0 ; i < N ; i++) 
    for (int j = 0 ; j < M ; j++) 
      if (arr[i][j] == '.' && find(visited.begin(), visited.end(), make_pair(i, j)) == visited.end())
          arr[i][j] = 'P';
  
  draw();
  return 0;
}
