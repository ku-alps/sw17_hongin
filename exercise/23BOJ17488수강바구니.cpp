#include<iostream>

#define MAX 1000
#define DEBUG 1
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int N, M;
int L[MAX] = {0,};
int C[MAX] = {0,};
bool B[MAX+1][MAX+1];
bool S[MAX+1][MAX+1];

int main() {
  cin >> N >> M;

  rep(i, 1, M+1)
    cin >> L[i];

  rep(r, 1, N+1)
    rep(c, 1, M+1)
      B[r][c] = 0, S[r][c] = 0;


  rep(i, 1, N+1){
    int in; do { cin >> in; B[i][in] = true; C[in]++; } while(in!=-1);
  }

  if (DEBUG){
    puts("");
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << B[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    rep(c, 1, M+1) {
      cout << C[c] << " ";
    }
    cout << "\n" ;
    rep(c, 1, M+1) {
      cout << L[c] << " ";
    }
    cout << "\n" ;
    cout << "\n" ;
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << S[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    cout << "\n";
  }

  rep(c, 1, M+1) {
    if (C[c] <= L[c]){
      L[c] -= C[c];
      C[c] = 0;
      rep(r, 1, N+1) {
        if (B[r][c]){
          S[r][c] = true;
          B[r][c] = false;
        }
      }
    }
  }

  if (DEBUG){
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << B[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    rep(c, 1, M+1) {
      cout << C[c] << " ";
    }
    cout << "\n" ;
    rep(c, 1, M+1) {
      cout << L[c] << " ";
    }
    cout << "\n" ;
    cout << "\n" ;
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << S[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    cout << "\n";
  }

  rep(i, 1, N+1){
    int in; do { cin >> in; B[i][in] = true; C[in]++; } while(in!=-1);
  }

  if (DEBUG){
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << B[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    rep(c, 1, M+1) {
      cout << C[c] << " ";
    }
    cout << "\n" ;
    rep(c, 1, M+1) {
      cout << L[c] << " ";
    }
    cout << "\n" ;
    cout << "\n" ;
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << S[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    cout << "\n";
  }

  rep(c, 1, M+1) {
    if (C[c] <= L[c]){
      L[c] -= C[c];
      C[c] = 0;
      rep(r, 1, N+1) {
        if (B[r][c]){
          S[r][c] = true;
          B[r][c] = false;
        }
      }
    }
  }

  if (DEBUG){
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << B[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    rep(c, 1, M+1) {
      cout << C[c] << " ";
    }
    cout << "\n" ;
    rep(c, 1, M+1) {
      cout << L[c] << " ";
    }
    cout << "\n" ;
    cout << "\n" ;
    rep(r, 1, N+1){
      rep(c, 1, M+1){
        cout << S[r][c] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    cout << "\n";
  }


  rep(r, 1, N+1) {
    bool manghae = true;
    rep(c, 1, M+1) {
      if (S[r][c]){
        cout << c << " ";
        manghae = false;
      }
    }
    if (manghae)
      cout << "망했어요";
    cout << "\n";
  }

  return 0;
}
