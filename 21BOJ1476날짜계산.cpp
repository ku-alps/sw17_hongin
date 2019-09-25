#include<iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int E, S, M;
  cin >> E >> S >> M;
  //E %= 15;
  //S %= 28;
  //M %= 19;
  int e = 1, s = 1, m = 1; 
  int n = 1;
  while(true){
    if (e == E && s == S && m == M)
      break;
    n++;
    e++;
    s++;
    m++;
    if (e == 16) e = 1;
    if (s == 29) s = 1;
    if (m == 20) m = 1;
    
  }
  cout << n << "\n";

  return 0;
}
