#include<iostream>
#include<vector>
#include<set>

#define VMAX 20000
#define EMAX 3000000

using namespace std;


int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int V, E, K; cin >> V >> E >> K;

  vector<vector<pair<int, int > > > g(V+1);
  while(E--) {
    int u, v, w; cin >> u >> v >> w;  
    g[u].push_back(make_pair(v, w));
    //g[v].push_back(make_pair(u, w));
  }

  // for (int i = 0 ; i < g.size(); i++) {
  //   cout << i  << " : " ;
  //   for (int j = 0 ;  j < g[i].size() ; j++) {
  //     cout << g[i][j].first << "-" << g[i][j].second << ", ";
  //   }
  //   cout << "\n";
  // }
  
  set<pair<int, int> > q; q.insert(make_pair(K, 0));
  vector<int> distance(V+1, -1); distance[K] = 0;
  vector<bool> visited(V+1, 0); visited[K] = 0;

  while(!q.empty()) {
    pair<int, int> visit = *q.begin();
    int vertex = visit.first;
    int sum = visit.second;
    q.erase(q.begin());
    // cout << vertex << " visited : ";
    // for (int i = 1; i <= V; i++)
    //   cout << distance[i] << " ";
    // cout << endl;
    if (visited[vertex]) continue;
    visited[vertex] = true;

    for (int i = 0 ; i < g[vertex].size(); i++) {
      int neighbor = g[vertex][i].first, weight = g[vertex][i].second;
      if (visited[neighbor]) continue;
      if (distance[neighbor] < 0 || distance[neighbor] > sum + weight){
        distance[neighbor] = sum + weight;
        q.insert(make_pair(neighbor, distance[neighbor]));
      }
    }
  }
  for (int i = 1; i <= V; i++){
    if (distance[i]==-1)
      cout << "INF\n";
    else
      cout << distance[i] << "\n";
  }
  

  return 0;
}
