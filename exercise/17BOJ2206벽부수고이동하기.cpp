#include <iostream>
#include <queue>
#include <cstring>
#define loop(i, n) for(int i = 0 ; i < n ; i++)
using namespace std;

class Item {
public:
  int r;
  int c;
  int d;
  int cy;
  int cx;
  int cb;
  Item(int x, int y, int z, int a, int b, int c) 
    : r(x), c(y), d(z), cy(a), cx(b), cb(c) {}
};

int N, M;
int arr[1000][1000];
bool visited[1000][1000];

int main() {
  cin >> N >> M;
  string line;
  loop(n, N){
    cin >> line;
    loop(m, M)
      arr[n][m] = line[m] - '0';
  }

  /*loop(n, N){
    loop(m, M)
      cout << arr[n][m];  
    cout << endl;
  }*/

  queue<Item> q;
  Item start(0, 0, 0, -1, -1, -1);
  q.push(start);
  visited[0][0] = 1;
  while(!q.empty()) {
    Item item = q.front();
    q.pop();

    if (item.r == N - 1 && item.c == M -1 ){
      cout << item.d << endl;
      return 0;
    }

    if (item.cb == 1) {
      arr[item.cy][item.cx] = 0;
    }
    
    if (item.r < N && visited[item.r+1][item.c] == false) {
      if(arr[item.r+1][item.c] == 0)
          q.push(Item(item.r+1, item.c, item.d+1, item.cy, item.cx, item.cb));
      if (item.cb == -1 && arr[item.r+1][item.c] == 1)
          q.push(Item(item.r, item.c, item.d, item.r+1, item.c, 1));
      visited[item.r+1][item.c] = true;
    }
    
    if (0 < item.r && visited[item.r-1][item.c] == false) {
      if (arr[item.r-1][item.c] == 0)
          q.push(Item(item.r-1, item.c, item.d+1, item.cy, item.cx, item.cb));
      if (item.cb == -1 && arr[item.r-1][item.c] == 1)
          q.push(Item(item.r, item.c, item.d, item.r-1, item.c, 1));
      visited[item.r-1][item.c] = true;
    }
    
    if (item.c < M && visited[item.r][item.c + 1] == false) {
      if (arr[item.r][item.c+1] == 0)
          q.push(Item(item.r, item.c+1, item.d+1, item.cy, item.cx, item.cb));
      if (item.cb == -1 && arr[item.r][item.c+1] == 1)
          q.push(Item(item.r, item.c, item.d, item.r, item.c+1, 1));
      visited[item.r][item.c+1] = true;
    }
    
    if (0 < item.c && visited[item.r][item.c-1] == false) {
      if (arr[item.r][item.c-1] == 0)
          q.push(Item(item.r, item.c-1, item.d+1, item.cy, item.cx, item.cb));
      if (item.cb == -1 && arr[item.r][item.c-1] == 1)
          q.push(Item(item.r, item.c, item.d, item.r, item.c-1, 1));
      visited[item.r][item.c-1] = true;
    }
        
    if (item.cb == 1) {
      arr[item.cy][item.cx] = 1;
    }
  }
  cout << "-1"<< endl;
  return 0;
}

