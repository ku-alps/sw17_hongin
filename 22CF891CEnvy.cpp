#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAXSIZE 500001

using namespace std;

int root[MAXSIZE];

int find(int x) {  return root[x] == x ? x : root[x] = find(root[x]);}
void unite(int x, int y) {  root[find(x)] = find(y); }

int n, m, q, ki[MAXSIZE];

int kruskal(vector<pair<int, pair<pair<int, int>, int > > > g) {
  sort(g.begin()+1, g.end());
  for (int i = 0; i < MAXSIZE; i++) 
    root[i] = i;

  int sum, cnt, idx; sum = 0; cnt =0; idx =1;

  for (idx = 1 ; idx <= m && cnt < n-1 ; idx++) {
    int u, v, w; u = g[idx].second.first.first; v = g[idx].second.first.second; w = g[idx].first;

    if (find(u) != find(v)) {
      unite(u, v);
      cnt++;
      sum += w;
    }
  }

  if (cnt != n-1) return -1;
  return sum;
}

int kruskal(vector<pair<int, pair<pair<int, int>, int > > > g,vector<int>edges) {
  for (int i = 0; i < MAXSIZE; i++) 
    root[i] = i;

  int sum, cnt, idx; sum = 0; cnt =0; idx =1;

  for (int i = 0 ; i < edges.size() && idx <= m && cnt < n -1; i++, idx++) {
    int u, v, w; u = g[edges[i]].second.first.first; v = g[edges[i]].second.first.second; w = g[edges[i]].first;

    if (find(u) != find(v)) {
      unite(u, v);
      cnt++;
      sum += w;
    }
  }

  if (cnt != edges.size()) { return -1;}
  sort(g.begin()+1, g.end());

  for (idx = 1 ; idx <= m && cnt < n-1 ; idx++) {
    if (find(edges.begin(), edges.end(), g[idx].second.second) != edges.end()) continue;

    int u, v, w; u = g[idx].second.first.first; v = g[idx].second.first.second; w = g[idx].first;
    
    if (find(u) != find(v)) {
      unite(u, v);
      cnt++;
      sum += w;
    }
  }

  if (cnt != n-1) { return -1;}
  return sum;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  vector<pair<int, pair<pair<int, int>, int> > > g;
  cin >> n >> m;

  g.push_back(make_pair(0, make_pair(make_pair(0, 0), 0)));
  for (int i = 1; i <= m; i++){
    int u, v, w; cin >> u >> v >> w;
    g.push_back(make_pair(w, make_pair(make_pair(u, v), i)));
  }
  
  int ans = kruskal(g);
  
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int k, ki; cin >> k; vector<int> edges;
    while(k--) { cin >> ki; edges.push_back(ki); }
    int pred = kruskal(g, edges);
    if (ans == pred) cout << "YES\n"; else cout<< "NO\n";
  }

  return 0;
}
