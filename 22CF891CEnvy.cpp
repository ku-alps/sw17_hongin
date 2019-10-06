#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int root[100001];

int find(int x) {
  if (root[x] == x)
    return x;
  return root[x] = find(root[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  root[x] = y;
}

int n, m, q;
vector<pair<int64_t, pair<int64_t, int64_t> > > g;

bool kruskal(vector<int>edges) {
  for (int i = 0; i <= 100001; i++) 
    root[i] = i;

  int sum, cnt, idx; sum = 0; cnt =0; idx =1;

  // push pregiven edges by uniting vertices
  for (int i = 0 ; i < edges.size() && idx <= m && cnt < n -1; i++, idx++) {
    int u, v, w; u = g[edges[i]].second.first; v = g[edges[i]].second.second; w = g[edges[i]].first;

    cout << edges[i]<< " " << u << " " << v << " " << w << endl;
    if (find(u) != find(v)) {
      unite(u, v);
      cnt++;
      sum += w;
    }
  }

  if (cnt != edges.size()) return false;

  for ( ; idx <= m && cnt < n-1 ; idx++) {
    int u, v, w; u = g[idx].second.first; v = g[idx].second.second; w = g[idx].first;

    if (find(u) != find(v)) {
      unite(u, v);
      cnt++;
      sum += w;
    }
  }

  return (cnt == n-1);
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;

  g[0] = make_pair(0, make_pair(0, 0));
  for (int i = 1; i <= m; i++){
    int u, v, w; cin >> u >> v >> w;
    g[i] = make_pair(w, make_pair(u, v));
  }
  
  sort(g.begin(), g.end());

  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int k; cin >> k; vector<int> edges(k);
    while(k) { cin >> edges[--k]; }
    if (kruskal(edges)) cout << "YES\n"; else cout<< "NO\n";
  }

  return 0;
}
