#include<iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int count = 0;
  int N;
  for (int t = 1 ; t <= n; t++) {
    N = t;
    int digit[4];
    int mag = 0;
    while(true) {
       digit[mag++] = N % 10;
       N /= 10;
       if (N==0)
         break;
    }

    int d;
    if (mag > 1)
      d = digit[1] - digit[0];
    else {
      count++;
      continue;
    }
       
    int i;
    for (i = 1 ; i < mag ; i++) {
      if (digit[i] - digit[i-1] != d)
        break;
    }
    if (i == mag)
      count ++;
  }
  cout << count << "\n";
  return 0;
}
