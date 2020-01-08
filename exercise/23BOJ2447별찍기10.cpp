#include<iostream>
#include<cmath>

using namespace std;

char arr[6561][6561];

void print(int N, int r, int c){
  if (N==0) return;
  int M = N/3, M2 = 2*M;
  for (int i = M; i < M2; i++) {
    for (int j = M ; j < M2; j++) {
      arr[r+i][c+j] = ' ';
    }
  }

  print(M, r + 0, c + 0);
  print(M, r + 0, c + M);
  print(M, r + 0, c + M2);
  print(M, r + M, c + 0);
  print(M, r + M, c + M);
  print(M, r + M, c + M2);
  print(M, r + M2, c + 0);
  print(M, r + M2, c + M);
  print(M, r + M2, c + M2);

}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N; cin >> N;

  for (int i = 0 ; i < N; i++)
    for (int j = 0 ; j < N ; j++)
      arr[i][j] = '*';

  print(N, 0, 0);
  for (int i = 0 ; i < N; i++){
    for (int j = 0 ; j < N ; j++){
      cout << arr[i][j];
    }
    cout << "\n";
  }
  


  return 0;
}
