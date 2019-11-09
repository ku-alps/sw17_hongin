#include<cstdio>
#include<vector>
using namespace std;

#define MAX 101

#define DD(x) do { cerr << #x << " : " << x << "\n"; } while(0);
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define BG 1

int N, M, D[MAX][MAX][MAX];

void show(){


}

int main() {
  scanf("%d %d", &N, &M);
  FOR(i, 1, N+1){
    FOR(j, 1, N+1) {
      D[0][i][j] = INT_MAX;
    }
  }

  int from, to;
  FOR(i, 0, M){
    scanf("%d %d", &from, &to);
    D[0][from][to] = 1; D[0][to][from] = 1;
  }

  FOR(k, 1, N+1) {
    if (BG) printf("%d\n", k);
    FOR(i, 1, N+1) {
      FOR(j, 1, N+1) {
        D[k][i][j] = min(D[k-1][i][j], D[k-1][i][k-1]+D[k-1][k-1][j]);
        if (BG) printf("%d\t", D[k][i][j]);
      }
      if (BG) printf("\n");
    }
    if (BG) printf("\n");
  }

  return 0;
}
