#include<iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  if (90<= n && n <=100)
    cout << "A" << '\n';
  else if (80 <= n && n <=89)
    cout << "B" << '\n';
  else if (70 <= n && n <=79)
    cout << "C" << '\n';
  else if (60 <= n && n <=69)
    cout << "D" << '\n';
  else
    cout << "F" << '\n';
  return 0;
}
