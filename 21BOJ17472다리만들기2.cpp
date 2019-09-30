#include<iostream>
#include<utility>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

#define range(a, x, b) a <= x && x < b

int A[10][10];
int N, M, I;
int D[6][6];
int dr[4] = {-1, 0, 1, 0}; // L U N D
int dc[4] = {0, 1, 0, -1};
vector<vector<pair<int, int>>> islands;

void read() {
  cin >> N >> M;
  for (int r = 0 ; r < N ; r++){
    for (int c = 0 ; c < M ; c++) {
      cin >> A[r][c];
    }
  }
}

void print_array() {
  for (int r = 0 ; r < N ; r++){
    for (int c = 0 ; c < M ; c++) {
      cout << A[r][c];
    }
    cout << "\n";
  }
}

void dfs(int r, int c, int I) {
  A[r][c] = 0;
  islands.at(I).push_back(make_pair(r, c));

  for (int i = 0 ; i < 4; i++) {
    if (A[r+dr[i]][c+dc[i]] && range(0, r+dr[i], N) && range(0, c+dc[i], M))
      dfs(r+dr[i], c+dc[i], I);
  }
}

void find_island() {
  I = 0;
  for ( int r = 0 ; r < N; r++) {
    for (int c = 0 ; c < M; c++) {
      if (A[r][c]){
        vector<pair<int, int> > island;
        islands.push_back(island);
        dfs(r, c, I++);
      }
    }
  }
}

void print_island() {
  cout << I << endl;
  for (int i = 0 ; i < I; i++) {
    for (int p = 0 ; p < islands.at(i).size(); p++) {
      cout << islands.at(i).at(p).first << ", " << islands.at(i).at(p).second << "\n";
    }
    cout << "\n";
  }
}

void get_distance_matrix() {
  for (int r = 0; r < 6; r++) {
    for (int c = 0 ; c < 6 ; c++) {
      D[r][c] = numeric_limits<int>::max();
    }
  } 

  for (int i = 0 ; i < I ; i++) {
    vector<pair<int, int> > island = islands.at(I);
    for (int p = 0 ; p < island.size(); p++) {
      pair<int, int> point = island.at(p);
      for (int x = 0 ; x < 4; x++) {
        int r = point.first;
        int c = point.second;
        int d = 0;
        while(!A[r+dr[x]][c+dc[x]]) {
          r = r + dr[x];
          c = c + dc[x];
          d++;
        }
        pair<int, int> extend = make_pair(r, c);
        for (int ii = 0 ; ii < I ; ii++) {
          if(i != ii && d < D[i][ii] && find(islands.at(ii).begin(), islands.at(ii).end(), extend) != islands.at(ii).end()) {
            D[i][ii] = d;
            D[ii][i] = d;
          }
        }
      }
    }
  }
}

void print_distnace_matrix() {
  for (int n = 0 ; n < N; n++) {
    for (int m = 0 ; n < M ; m++) {
      cout << A[n][m] << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  read();
  print_array();
  find_island();
  print_island();
  get_distance_matrix();
  //print_distnace_matrix();

  return 0;
}
