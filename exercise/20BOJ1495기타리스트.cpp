#include <iostream>
#include <cstring>
using namespace std;

int N, S, M; // no, start, max
int V[101]; // diff
bool cache[101][1050]; // N x M

int main() {
  // in
  cin >> N >> S >> M;
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }

  //init
  memset(cache, false, sizeof(cache));
  cache[0][S] = true;

  //dp
  for (int i = 1; i <= N; i++) {
    bool changed = false;

    for (int j = 0; j <= M; j++) {
      if (!cache[i-1][j]) continue;

      if (j + V[i-1] <= M){
        cache[i][j + V[i-1]] = true;
        changed = true;
      }

      if (0 <= j - V[i-1]){
        cache[i][j - V[i-1]] = true;
        changed = true;
      }
    }

    if (!changed) {cout << -1 << endl; return 0;}

    for (int j = 0 ; j <= M; j++)
      cout << cache[i][j] << " ";
    cout << endl;
  }

  //max 
  int max = 0;
  for (int j = M ; j >= 0; j--) {
    if (cache[N][j]) {
      max = j;
      break;
    }
  }

  cout << max << endl;

  return 0;
}
