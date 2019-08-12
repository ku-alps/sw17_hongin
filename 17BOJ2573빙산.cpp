#include<iostream>
#include<vector>
#define loop(i, n) for (int i = 0 ; i < n; i++)
using namespace std;

int R, C;
int h[300][300];
int connected_component() {
  vector<int> group[10000];
  int counter = 1, duplicate = 0;
  int g[300][300] = {0,};

  /*for (int i = 0 ; i < R; i++)
    g[i][0] = 0;
  for (int i = 0 ; i < C; i++)
    g[0][i] = 0; */

  for (int r = 1; r < R; r++) {
    for (int c = 1; c < C; c++) {
      if (h[r][c] > 0) {
        if (g[r-1][c] > 0 && g[r][c-1] > 0 && g[r-1][c] != g[r][c-1]) {
          int size = counter - duplicate;
          if (duplicate == 0) group[0].push_back(1);
          for (int d = 0 ; d < size; d++) {
            if (find(group[d].begin(), group[d].end(),g[r-1][c])==group[d].end()){ 
              group[d].push_back(g[r][c-1]);
              duplicate++;
            }
            if (find(group[d].begin(), group[d].end(),g[r][c-1])==group[d].end()){
              group[d].push_back(g[r-1][c]);
              duplicate++;
            }
          }
          g[r][c] = g[r-1][c];
        }
        else if (g[r-1][c] > 0) g[r][c] = g[r-1][c];
        else if (g[r][c-1] > 0) g[r][c] = g[r][c-1];
        else if (g[r-1][c] == 0 && g[r][c-1] == 0) g[r][c] = counter++;
      } /*else {
        g[r][c] = 0;
      }*/
    }
  }
  
  cout << "Grouping" << endl;
  loop(r, R) {
    loop(c, C) {
      cout << g[r][c] << " ";
    }
    cout << endl;
  }

  loop(i, duplicate){
    loop(j, group[i].size()){
      cout << group[i].at(j) << " ";
    } cout << endl;
  }
  cout << "counter " << counter<< endl;
  cout << "duplicate " << duplicate<< endl;
  
  int group_size = counter - duplicate;
  cout << "group_size " << group_size << endl;
  return group_size;
}

void meltdown() {
  int minus[300][300] = {0,};
  loop(r, R) {
    loop(c, C) {
      if (h[r][c] > minus[r][c] && h[r-1][c] == 0)
        minus[r][c] += 1;
      if (h[r][c] > minus[r][c] && h[r+1][c] == 0)
        minus[r][c] += 1;
      if (h[r][c] > minus[r][c] && h[r][c-1] == 0)
        minus[r][c] += 1;
      if (h[r][c] > minus[r][c] && h[r][c+1] == 0)
        minus[r][c] += 1;
    }
  }

  loop(r, R) {
    loop(c, C) {
      h[r][c] -= minus[r][c];
    }
  }

  cout << "Meltdown" << endl;
  loop(r, R) {
    loop(c, C) {
      cout << h[r][c] << " ";
    }
    cout << endl;
  }

}

int main() {
  cin >> R >> C;
  loop(r, R) {
    loop(c, C) {
      cin >> h[r][c];
    }
  }

  //connected_component();
  //meltdown();
  int answer = 0;
  while(true) {
    int group = connected_component();
    if (group == 0) 
      break;
    else if (group > 1){
      cout << "answer " << answer << endl;
      return 0;
    }
    meltdown();  
    answer++;
  }

  cout << "answer " << 0<< endl;
  return 0;
}
