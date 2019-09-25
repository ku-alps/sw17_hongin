#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int A[3];
  cin >> A[0] >> A[1] >> A[2];
  sort(A, A+3);
  cout << A[1];

  return 0;
}
