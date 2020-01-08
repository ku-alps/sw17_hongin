#include<iostream>
#include<cmath>

using namespace std;

int visit(int N, int r, int c){
  if (N==1) {
    if (r == 0 && c == 0)
      return 0;
    else if (r == 0 && c == 1)
      return 1;
    else if (r == 1 && c == 0)
      return 2;
    else if (r == 1 && c == 1)
      return 3;
  }

  int M = pow(2, N-1);
  if (r < M && c < M)
    return visit(N-1, r, c);
  else if (r < M && M <= c)
    return M*M + visit(N-1, r, c-M);
  else if (M <= r && c < M)
    return 2*M*M + visit(N-1, r-M, c);
  else if (M <= r && M <= c)
    return 3*M*M + visit(N-1, r-M, c-M);
}
int main() {
  int N, r, c;
  cin >> N >> r >> c;
  cout << visit(N, r, c) << endl;

  return 0;
}
