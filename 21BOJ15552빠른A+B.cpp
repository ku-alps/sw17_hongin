#include<iostream>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  int A, B;
  for (int i=0; i<T; i++) {
    cin >> A >> B;
    cout << A+B << '\n';
  }
  return 0;
}
