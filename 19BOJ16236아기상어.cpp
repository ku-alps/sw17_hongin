#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define B 0
#define S 9
using namespace std;

int N;
int arr[20][20];
int s = 2;
int e = 0;
int t = 0;
int x, y;
vector<pair<int, pair<int, int> > > fish_to_eat;

void debug() {
  for (int i = 0 ; i < N; i++){ 
    for (int j = 0 ; j < N; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout <<endl;
}

int bfs(int ox, int oy, int x, int y) {
  int visited[20][20] = {1, };
  int maxx = max(ox, x), minx = min(ox, x);
  int maxy = max(oy, y), miny = min(oy, y);

  for (int i = 0 ; i < N; i++) {
    for (int j = 0 ; j < N; j++) {
      if (minx <= j && j <= maxx && miny <= i && i <= maxy)
        visited[i][j] = 0;
    }
  }

  queue<pair<int, int> > coord;
  queue<int> depth;
  
  coord.push(make_pair(ox, oy));
  depth.push(0);

  while(!coord.empty()){
    pair<int, int> c = coord.front();
    int d = depth.front();
    coord.pop();
    depth.pop();

    if (c.first == x && c.second == y)
      return d;
    
    if (c.first < x && !visited[c.second][c.first + 1]){
      coord.push(make_pair(c.first + 1, c.second));
      depth.push(d+1);
    }
    if (x < c.first && !visited[c.second][c.first - 1]){
      coord.push(make_pair(c.first - 1, c.second));
      depth.push(d+1);
    }
    if (c.first < y&& !visited[c.second + 1][c.first]){
      coord.push(make_pair(c.first, c.second + 1));
      depth.push(d+1);
    }
    if (y < c.first&& !visited[c.second - 1][c.first]){
      coord.push(make_pair(c.first, c.second - 1));
      depth.push(d+1);
    }
  }
  
  return -1;
}

int main() {
  cin >> N;
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N ; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 9) { y = i; x = j; }
    }
  }

  while(true) {
    debug();
    fish_to_eat.clear();

    // find all fish to eat
    for (int i = 0 ; i < N; i++)
      for (int j = 0 ; j < N; j++)
        if (arr[i][j] != B && arr[i][j] < s)
          fish_to_eat.push_back(make_pair(arr[i][j], make_pair(i, j)));
      
    // no fish to eat
    if (fish_to_eat.size() == 0)
      break;

    // find shortest & top & left
    int d, min = 20*20; 
    pair<int, int> target, temp;
    for (int i = 0; i < fish_to_eat.size(); i++){
      temp = fish_to_eat.at(i).second;
      d = bfs(x, y, temp.second, temp.first);
      if (d < min) {
        target = temp;
        min = d;
      }
    }

    // move and eat
    arr[y][x] = 0;
    y = target.first;
    x = target.second;
    arr[y][x] = 9;

    // get bigger
    e++;
    if (e == s) { s++; e = 0; }

    // count time
    t += d;
  }
  cout << t << endl;
  return 0;
}
