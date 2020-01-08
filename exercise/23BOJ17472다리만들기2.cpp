#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 10
#define DB(x) do { cerr << #x << "=" << x << " "; } while(0)
#define DD(x) do { cerr << #x << "=" << x << "\n"; } while(0)
#define ON(x, a, b) ( a <= x && x < b )
#define IN(x, y) find(x.begin(), x.end(), y) != x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int N, M;
int arr[MAX][MAX];
int bkup[MAX][MAX];
int I;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<pair<int, int> > islands[6];

void dfs(vector<pair<int, int> > &island, int r, int c) {
  bkup[r][c] = 0;
  island.push_back(make_pair(r, c));

  rep(d, 0, 4) {
    if (bkup[r+dr[d]][c+dc[d]])
      dfs(island, r+dr[d], c+dc[d]);
  }
}

int main() { 
  cin >> N >> M;

  // read
  rep(r, 0, N) {
    rep(c, 0, M) {
      cin >> arr[r][c];
      bkup[r][c] = arr[r][c];
    }
  }

  // find island
  I = 0;
  rep(r, 0, N) {
    rep(c, 0, M) {
      if (bkup[r][c]) {
        dfs(islands[I++], r, c);        
      }
    }
  }

  //puts("");

  // rep(r, 0, N) {
  //   rep(c, 0, M) {
  //     cout << arr[r][c] << " ";
  //   } cout << "\n";
  // }
  // 
  // DD(I);
  // rep(i, 0, I) {
  //   rep(j, 0, islands[i].size()) {
  //     cout << islands[i][j].first << ","<< islands[i][j].second << " ";
  //   } cout << "\n";
  // }
 
  // find distance
  int dist[I][I];
  rep(i, 0, I){
    rep(j, 0, I) {
      dist[i][j] = 10;
    }
  }

  rep(from, 0, I) {
    rep(ref, 0, islands[from].size()) {
      int r = islands[from][ref].first;
      int c = islands[from][ref].second;
      rep(o, 0, 4) {
        int nr = r+dr[o], nc = c+dc[o];
        int d = 0;

        // no land
        if (arr[nr][nc]) continue;

        // go till edge
        while( ON(nr, 0, N) && ON(nc, 0, M)){
          DB(r); DB(c); DB(nr); DB(nc); DD(d);
          // if land
          if (arr[nr][nc]){
            // find which island
            pair<int, int> tar = make_pair(nr, nc);
            rep(to, 0, I) {
              if (from != to && d < dist[from][to] && IN(islands[to], tar)){
                dist[from][to] = d; dist[to][from] = d;
              }
            }
          }
          d++; nr+=dr[o]; nc+=dc[o];
        }
      }
    }
  }

  //print dist
  rep(i, 0, I){
    rep(j, 0, I) {
      cout << dist[i][j] << " ";
    } cout << "\n";
  }
 
  // prim
  bool visited[MAX] = {0,}; visited[0] = 1;
  int sum = 0;
  rep(round, 0, I-1) {
    int idx=-1, min=10; 
    //DD(round);
    rep(r, 0, I) { 
      if (visited[r]){
        //DD(r);
        rep(c, 0, I) {
          if (!visited[c] && dist[r][c] < min){
            //DB(c); DD(dist[r][c]);
            idx = c;
            min = dist[r][c];
          }
        }
      }
    }
    if (idx<0) { cout << "-1" << "\n"; return 0;}
    visited[idx] = 1; sum += min;
    //DB(idx); DB(min); DD(sum);
  }

  cout << sum << "\n";

  return 0;
}
