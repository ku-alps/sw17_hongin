#include<iostream>
using namespace std;

int main() {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  int lhs = x < w - x ? x : w - x;
  int rhs = y < h - y ? y : h - y;
  cout << (lhs < rhs ? lhs : rhs) << endl;
  return 0; 
}
