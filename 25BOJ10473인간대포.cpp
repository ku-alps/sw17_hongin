#include<iostream>
#include<cfloat>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

#define BG 0
#define DB(x) do { cerr << #x << ":" << x << " "; } while(0);
#define DD(x) do { cerr << #x << ":" << x << "\n"; } while(0);

#define N 105

typedef pair<float, float> point;

float dist(point A, point B) {
  float dx = A.first - B.first;
  float dy = A.second - B.second;
  return sqrt(dx*dx + dy*dy);
}

void vis(vector<vector<float> > &g) {
  FOR(i, 0, g.size()) {
    FOR(j, 0, g[i].size()) {
      printf("%f ", g[i][j]);
    }
    printf("\n");
  }
  
}

int main() {
  int n;
  point s, t, e;
  vector<point> cannon;

  // read
  scanf("%f %f", &s.first , &s.second); cannon.push_back(s); 
  scanf("%f %f", &e.first , &e.second); cannon.push_back(e);
  scanf("%d", &n);
  FOR(i, 0, n){
    scanf("%f %f", &t.first, &t.second); cannon.push_back(t);    
  }

  if(BG){
  FOR(i, 0, n+2) {
    printf("%f %f\n", cannon[i].first, cannon[i].second);
  }
  }

  // cost
  vector<vector<float> > g(n+2);
  FOR(i, 0, n+2) {
    FOR(j, 0, n+2) {
      float d = dist(cannon[i], cannon[j]);
      float t;
      if (i!=0&&i!=1)
        t = min(d/5, fabs(d-50)/5+2);
      else
        t = d/5;
      if (BG){
      DB(i); DB(j); DB(d); DD(t);
      }
      g[i].push_back(t);
    }
  }
  if(BG){
    vis(g);
  }

  // init
  vector<float>dmin(N, FLT_MAX);
  if(BG){
  printf("dmin\n");
  FOR(i, 0, n+2) {
    printf("%f\n", dmin[i]);
  }
  }
  bool visited[N] = {0, };
  typedef pair<float, pair<point, int> > T;
  priority_queue<T, vector<T>, greater<T> > pq;
  t.first = s.first, t.second = s.second;
  pq.push(make_pair(0, make_pair(t, 0)));
  visited[0] = true;
  dmin[0] = 0;

  while(!pq.empty()) {
    pair<float, pair<point, int> > top = pq.top(); pq.pop();
    float d = top.first;
    point p = top.second.first;
    int i = top.second.second;
    visited[i] = true;
    if (BG){
    DB(i); DB(d); DB(p.first); DB(p.second); DD(visited[i]);
    FOR(i, 0, n+2) { printf("%f ", dmin[i]); } printf("\n");
    FOR(i, 0, n+2) { printf("%d ", visited[i]); } printf("\n");
    }
    if (dmin[i] > d) dmin[i] = d;
    if (p == e) { printf("%f\n", dmin[1]); return 0; }

    FOR(j, 0, n+2) {
      if (!visited[j] && d+g[i][j] < dmin[j]) {
        if (BG) {
        DB(j); DB(d); DB(g[i][j]); DB(dmin[j]); 
        }
        dmin[j] = d+g[i][j];
        if (BG) {
        DD(dmin[j]);
        }
        pq.push(make_pair(dmin[j], make_pair(cannon[j], j)));
      }
    }
  }
  printf("%f\n", dmin[1]);

  return 0;
}
