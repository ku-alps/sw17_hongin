#include<iostream>
#include<string>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int alphabet[26];
  for (int i = 0 ; i < 26; i++)
    alphabet[i] = -1;
  string word;
  cin >> word;

  int index;
  for (int i = 0 ; i < word.length(); i++) {
    index = word[i] - 'a';  
    if (alphabet[index] == -1)
      alphabet[index] = i;
  }
  for (int i = 0 ; i < 26; i++) {
    cout << alphabet[i] << ' ';
  }
  return 0;
}
