#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
  getline(cin, str);

  char buf[5];
  int ind = 0;
  int min = 0; 
  //cout << "str len is " << str.length() << endl;
  for (int i = 0 ; i < str.length() ; i++) {
    if (str[i]=='-') {
      int num;
      cout << num << endl;
      ind = 0;
    } else if (str[i] == '+') {
    } else {
    }
  }
    


  return 0;
}
