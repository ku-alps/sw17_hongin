#include <iostream>
using namespace std;
char code[5001];

int main() {
  int n = 0;
  do {
    scanf("%c", &code[n]); 
  } while(code[n++] != '\n');

  for (int i = 0 ; i < n; i++) {
    cout << code[i];
  }

  return 0;
}
