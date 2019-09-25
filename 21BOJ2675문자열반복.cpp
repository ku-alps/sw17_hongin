#include<iostream>
#include<string>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  int T;
  cin >> T;

  string S;
  int R;
  for (int i = 0 ; i < T; i++) {
    cin >> R >> S;
    for (int j = 0 ; j< S.length(); j++) {
      for (int r = 0 ; r < R; r++) {
        cout << S[j];
      }
    }
    cout << '\n';
  }
  return 0;
}
