#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Computer {
public:
  int id;
  int distance;
  vector<int> neighbors;
  bool operator<(const Computer& t) const { return (this->id < t.id); }
};

int N, M;
int cost[1000][1000];
set<Computer> connected, seperate;
int main(){
  cin >> N >> M;
  int y, x, c;
  for (int i = 0; i < M; i++) {
    cin >> y >> x >> c ;
    cost[y-1][x-1] = c;
    cost[x-1][y-1] = c;
  }

  
  return 0;
}


