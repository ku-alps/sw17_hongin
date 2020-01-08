#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

#define INT 0x7fffffff
#define FOR(i,a,b)  for(int i = a; i <  b; i++)
#define IN(i, a, b) (a <= i) && (i < b)

#define DEBUG 0
#define DB(x) do {std::cerr << #x << ":" << x << " "; } while (0)
#define BG(x) do {std::cerr << #x << ":" << x << "\n"; } while (0)

using namespace std;

int N, M;
typedef pair<int, pair<int, int> > T;
priority_queue <T, vector<T>, greater<T> >pq;
int graph[100][100];
int dist[100][100];
bool visited[100][100];
int dc[4] = {-1, 0, 1, 0}, dr[4] = {0, -1, 0, 1};

template<class T>
void vis(T arr[][100]){
  FOR(r, 0, N) {
    FOR(c, 0, M) {
      if (arr[r][c]==0x7fffffff) printf("X");
      else printf("%d", arr[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  // read
  scanf("%d %d", &M, &N);
  FOR(r, 0, N)
    FOR(c, 0, M)
      scanf("%1d", &graph[r][c]), dist[r][c] = INT;

  if (DEBUG){
    vis<int>(graph);
  }

// dijkstra
  // init
  pq.push(T(0, pair<int, int>(0, 0)));
  visited[0][0] = true;
  dist[0][0] = 0;

  while(!pq.empty()) {
    // find
    T t = pq.top(); pq.pop();
    int d, r, c; d = t.first, r = t.second.first, c = t.second.second;
    if (dist[r][c] > d) dist[r][c] = d;
    if (DEBUG){
      DB(d); DB(r); BG(c);
      vis<int>(dist);
    }
    if (r == N-1 && c == M-1){ printf("%d\n", d); break; }

    // add
    FOR(n, 0, 4) {
      int nr, nc; nr = r+dr[n], nc = c+dc[n];

      if (!(IN(nr, 0, N) && IN(nc, 0, M))) continue;
      if (visited[nr][nc]) continue;

      if (graph[nr][nc]) {
        pq.push(make_pair(d+1, make_pair(nr, nc)));
        visited[nr][nc] = true;
      } else {
        pq.push(make_pair(d, make_pair(nr, nc)));
        visited[nr][nc] = true;
      }
    }
  }

  return 0;
}
