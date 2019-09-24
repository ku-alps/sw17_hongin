#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  // init
  int X, Y; // biggest x, y found
  cin >> X >> Y;
  int s[100000];
  s[0] = X + Y;

  // update biggest
  int x, y;
  int mx, my, Mx, My;
  for (int i = 1; i < N; i++) {
    cin >> x >> y;
    mx = x > X? X : x;
    my = y > Y? Y : y;
    Mx = x > X? x : X;
    My = y > Y? y : Y;

    if (mx + My >= Mx + my) {
      s[i] = mx + My;
      X = mx;
      Y = My;
    } else {
      s[i] = Mx + my;
      X = Mx;
      Y = my;
    }
    cout << s[i] << "\n";
  }

}
