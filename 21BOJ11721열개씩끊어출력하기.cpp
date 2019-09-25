#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  string s;
  getline(cin, s);

  for (int i = 0 ; i < s.length(); i++){
    cout << s[i];
    if (i % 10 == 9)
      cout << "\n";
  }
  return 0;
}
