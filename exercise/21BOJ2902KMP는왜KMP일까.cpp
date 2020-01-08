#include<iostream>
#include<string>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  string str;
  getline(cin, str);
  cout << str[0];
  for(int i = 1 ; i < str.length(); i++) {
    if (str[i-1] == '-')
      cout << str[i];
  }
  cout << "\n";
    
  return 0;
}
