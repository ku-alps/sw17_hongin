#include<iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int quo, rem, bonus = 0;
  while(true) {
    quo = N / 5;
    rem = N % 5;
    if ((rem+bonus) % 3 == 0)
      break;
    else{
      if (N > 5){
        N -= 5;
        bonus += 5;
      } else {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  cout << quo + (rem+bonus) / 3 <<'\n';
    
  return 0;
}
