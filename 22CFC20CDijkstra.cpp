#include<iostream>
using namespace std;

int N, M;
int g[100000][100000];
int dmin[100000];
bool T[100000];
int vpre[100000];
int main() {
  cin >> N >> M;
  int ai, bi, gi;

  for (int i = 0 ; i < M ; i++) {
    cin >> ai >> bi >> gi;
    g[ai-1][bi-1] = gi; 
    g[bi-1][ai-1] = gi;
  }

  for (int i = 0 ; i < N ; i++) {
    dmin[i] = g[0][i];
  }

  T[0] = true;
  
  return 0;  
}
