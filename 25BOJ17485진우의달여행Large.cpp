#include<iostream>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b ; i++)

#define BG 1

#define DB(x) do {cerr<< #x<<":"<< x<<" ";} while(0);
#define DD(x) do {cerr<< #x<<":"<< x<<"\n";} while(0);

int N, M;
int a[1001][1002];
int dp[1001][1002][3];
int d[1001][1002];

int MIN(int a, int b, int c) { return a < b? (a < c ? a : c) : (b < c ? b : c); }

void vis(int (&a)[1001][1002]) {
  FOR(r, 0, N+1){
    FOR(c, 0, M+2){
      cout << a[r][c] << " ";
    }
    cout << "\n";
  }
  cout << "\n" ;
}

void vis(int (&a)[1001][1002][3]) {
  FOR(r, 0, N+1){
    FOR(c, 0, M+2){
      FOR(i, 0, 3) {
        cout << a[r][c][i] << ",";
      }
      cout << " ";
    }
    cout << "\n";
  }
  cout << "\n" ;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N  >> M;
  FOR(r, 1, N+1){
    FOR(c, 1, M+1){
      cin >> a[r][c];
      d[r][c] = 0;
    }
  }

  FOR(r, 0, N+1){ 
    a[r][0] = 100; a[r][M+1] = 100;
    FOR(i, 0, 3){ 
      dp[r][0][i] = 100;
      dp[r][M+1][i] = 100;
    }
  }
  FOR(c, 0, M+2){ 
    a[0][c] = 0; 
    FOR(i, 0, 3){ 
      dp[0][c][i] = 0;
    }
  }
  
  if (BG) {
    vis(a);
    vis(dp);
    vis(d);
  }

  FOR(r, 1, N+1) {
    FOR(c, 1, M+1) {
      // ignore previous path
      dp[r][c][0] = min(dp[r-1][c-1][1], dp[r-1][c-1][2]) + a[r][c];
      dp[r][c][1] = min(dp[r-1][c][0], dp[r-1][c][2]) + a[r][c];
      dp[r][c][2] = min(dp[r-1][c+1][1], dp[r-1][c+1][2]) + a[r][c];
    }
    if(BG){
    DD(r);
    vis(dp);
    }
  }

  int ans = 100;
  FOR(c, 1, M+1) 
    FOR(i, 0, 3)
      if (ans > dp[N][c][i])
        ans = dp[N][c][i];
  cout << ans << "\n";


  return 0;
}
