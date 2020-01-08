#include<iostream>
#include<string>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.get(); // reading '\n'
  char n;
  int sum = 0;
  for (int i = 0 ; i <N ; i++) {
    cin.get(n);
    sum += (n - '0');
  }
  cout << sum << '\n';
  return 0;
}
