#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string str;
int val = 0;

int read_next_num(int& i) {
  int num = 0;
  for (; i < str.length(); i++){
    if (str[i] =='+' || str[i] == '-') {
      break; 
    } else {
      num = 10 * num + (str[i]  - '0');
    }
  }
  
  return num;
}
int main() {
  getline(cin, str);

  bool found_first_minus = false;
  
  for (int i = 0 ; i < str.length(); i++){
    // check for the '+' or '-'
    if (found_first_minus) {
      val -= read_next_num(i);
    } else {
      val += read_next_num(i);
      if (str[i] == '-') {
        found_first_minus = true;
      }
    }
  }
  cout << val << endl;
  return 0;
}
