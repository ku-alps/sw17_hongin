#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 200000
#define DB(x) do { std::cerr << #x << "=" << x << " "; } while (0) 
#define DD(x) do { std::cerr << #x << "=" << x << "\n"; } while (0) 

using namespace std;

int root[MAX];
int find(int x) { return root[x] == x ? x : root[x] = find(root[x]); }
void unite(int x, int y) { root[find(x)] = find(y); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);

  while(true){
    int N, M; cin >> N >> M;
    if ( N ==0 && M ==0) break;
   
    vector<pair<int, pair<int, int> > > g(M);
    int W; W = 0;
    for (int i = 0 ; i < M ; i++) {
      int u, v, w; cin >> u >> v >> w;
      g[i] = make_pair(w, make_pair(u, v));
      W += w;
    }

    sort(g.begin(), g.end());

    // for (int i = 0 ; i < M ; i++) {
    //   cout <<  g[i].second.first << " " << g[i].second.second << " " << g[i].first << endl;
    // }

    for (int i = 0 ; i < MAX ; i++)
      root[i] = i;

    int idx, sum, cnt; idx = 0, sum = 0, cnt = 0;
    for(; idx < M && cnt < N - 1; idx++) {
      int w, u, v; w = g[idx].first, u = g[idx].second.first, v = g[idx].second.second;
      //DB(idx); DB(w); DB(u); DB(v); DB(cnt); DD(sum);
      if (find(u) != find(v)) {
        //DB(u); DB(v); DB(root[u]); DD(root[v]);
        unite(u, v);
        cnt++; sum += w;
      }
    }

    if (cnt == N - 1) cout << W - sum << "\n";
  }
  return 0;
}
