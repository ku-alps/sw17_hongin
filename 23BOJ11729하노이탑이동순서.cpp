#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
vector<pair<int, int> > v;

void hanoi(int height, int from, int to, int other) {
  if (!height) return;
  hanoi(height - 1, from, other, to);
  v.push_back(make_pair(from, to));
  cnt++;
  hanoi(height - 1, other, to, from);
}

int main() {
  int n; cin >> n;
  hanoi(n, 1, 3, 2);
  cout << cnt << "\n";
  for (int i = 0 ; i < v.size() ; i++)
    cout << v[i].first << " "<< v[i].second << "\n";

  return 0;
}
