#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
using namespace std;

char L[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 
  'q', 'w', 'e', 'r', 't', 'y',
  'A', 'S', 'D', 'F', 'G',
  'a', 's', 'd', 'f', 'g',
  'Z', 'X', 'C', 'V', 'B', 
  'z', 'x', 'c', 'v', 'b'};

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string str;
  getline(cin, str);
  
  int left=0, right=0;
  int shift=0, space=0;
  for (int i = 0 ; i < str.length(); i++) {
    if (str[i] == ' ')
      space++;
    if ('A' <= str[i] && str[i] <= 'Z')
      shift++;
    if (find(begin(L), end(L), str[i]) != end(L))
      left++;
  }

  right = str.length() - space - left;
  int neutral = shift + space;

  while (neutral) {
    if (left <= right) {
      left++;
    } else {
      right++;
    }
    neutral--;
  }

  cout << left << " " << right;
  return 0;
}
