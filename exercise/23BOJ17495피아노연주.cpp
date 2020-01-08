#include<iostream>
#include<string>
using namespace std;

int encode(string str) {
  char c = str[0];
  int n = 0;
  for (int i = 1 ; i < str.length() - 1; i++ ) {
    n *= 10;
    n += 12 * (str[i]-'0');
  }

  int d[7] = {9, 11, 0, 2, 4, 5, 7};
  n += d[c - 'A'];

  if (str[str.length() - 1] == '#') {
    n += 1;
  } else {
    n += 12 * (str[str.length()-1]-'0');
  }
  
  return n;
}


int L, R, N, arr[1000];
int dp[2][1001];

int main() {
  string str;
  cin >> str;
  L = encode(str);
  cin >> str;
  R = encode(str);
  cin >> N;
  cout << endl<<L << " " << R << endl;

  for (int i = 0 ; i < N ; i++){
    cin >> str;
    arr[i] = encode(str);
  }

  for (int i = 0 ; i < N ; i++)
    cout << arr[i] << endl;
 
  dp[0][0]; // 해당음을 왼손으로 쳤을때의 값
  dp[0][1];
  for (int i = 1 ; i <= 1000; i++) {
  }
  
  return 0;
}
