#include<iostream>
using namespace std;

int N, M;
int L[1000];
int req[1001][1000];
int success[1000][1000];

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
 
  for (int i = 0 ; i < 1000; i++) {
    L[i] = 0;
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
    cin >> L[i];
  }

  for (int n = 0 ; n < N ; n++) {
    int in = 0;
    do {
      cin >> in;
      in--;
      req[n][in]++;
      req[1000][in]++;
    } while (in != -2);
  }

  for (int c = 0 ; c < M ; c++) {
    if (req[1000][c] <= L[c]){
      //cout << "reducing L["<< c <<"] from " << L[c];
      L[c] -= req[1000][c];
      //cout << " to " << L[c] << endl;
      req[1000][c] = 0;
      for (int r = 0 ; r < N ; r++) {
        if (req[r][c]){
          req[r][c] = 0;
          success[r][c] = 1;
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

  for (int c = 0 ; c < M ; c++) {
    //cout <<  "REQ " << c<< " : " << req[1000][c] << endl;
    if (req[1000][c] <= L[c]) {
      for (int r = 0 ; r < N ; r++) {
        if (req[r][c])
          success[r][c] = 1;
          req[r][c] = 0;
      }
    }
  }

  for (int i = 0 ; i < N ; i++ ){
    bool any = false;
    for (int j = 0 ; j < M; j++) {
      if (success[i][j]){
        cout << (j+1) << " ";
        any = true;
      }
    }

    if (!any)
      cout << "망했어요";
    cout << "\n";
  }

  return 0;
}
