#include<iostream>
using namespace std;

int N, M;
int to[1000];
int req[1001][1000];
int success[1000][1000];

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
 
  for (int i = 0 ; i < 1000; i++) {
    to[i] = 0;
    for (int j = 0 ; j < 1000; j++) {
      req[i][j] = 0;
      success[i][j] = 0;
    }
  }

  for (int j = 0 ; j < 1000; j++) {
    req[1000][j] = 0;
  }


  cin >> N >> M;
  for (int i = 0 ; i < M ; i++) {
    cin >> to[i];
  }

  for (int i = 0 ; i < N ; i++) {
    int in = 0;
    do {
      cin >> in;
      in--;
      req[i][in]++;
      req[1000][in]++;
    } while (in != -2);
  }

  for (int i = 0 ; i < M ; i++) {
    if (req[1000][i] <= to[i]){
      to[i] -= req[1000][i];
      for (int r = 0 ; r < N ; r++) {
        if (req[r][i]){
          success[r][i] = 1;        
          req[r][i] = 0;
          to[1000]--;
        }
      }
    }
  }

  for (int i = 0 ; i < N ; i++) {
    int in = 0;
    do { 
      cin >> in;
      in--;
      req[i][in]++;
      req[1000][in]++;
    } while (in != -2);
  }

  for (int i = 0 ; i < M ; i++) {
    if (req[1000][i] <= to[i]) {
      for (int r = 0 ; r < N ; r++) {
        if (req[r][i])
          success[r][i] = 1;        
      }
    }
  }

  for (int i = 0 ; i < N ; i++ ){
    int count = 0;
    for (int j = 0 ; j < M; j++) {
      if (success[i][j]){
        cout << (j+1) << " ";
        count++;
      }
    }

    if (!count)
      cout << "망했어요";
    cout << "\n";
  }

  return 0;
}
