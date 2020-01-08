#include<iostream>
#include<string>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  string str;
  getline(cin, str);
  string croatian[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
  int minus = 0;
  for (int i = 0 ; i < str.length() ; i++) {
    for (int j = 0 ; j < 8; j++) {
      int k;
      for (k = 0 ; k < croatian[j].length(); k++){
        if (i+k >= str.length())
          break;
        if (str[i+k] != croatian[j][k])
          break;
      }
      if (k == croatian[j].length()){
        minus += croatian[j].length() - 1;
        i += croatian[j].length() -1;
        break;
      }
      
    }

  }
  cout << str.length() - minus << '\n';
  return 0;
}
