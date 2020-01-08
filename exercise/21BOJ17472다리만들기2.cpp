#include<iostream>
#include<utility>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

#define range(a, x, b) a <= x && x < b
#define during(a, x, b) for (int x = a; x < b; x++)

int A[10][10];
int N, M, I;
int D[6][6];
int dr[4] = {0, -1, 0, 1}; // L U R D 
int dc[4] = {-1,  0, 1, 0};
vector<vector<pair<int, int> > > islands;

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
  int B[10][10];
  during(0, r, N)
    during(0, c, M)
      B[r][c] = A[r][c];
  
  for ( int r = 0 ; r < N; r++) {
    for (int c = 0 ; c < M; c++) {
      if (A[r][c]){
        vector<pair<int, int> > island;
        islands.push_back(island);
        dfs(r, c, I++);
      }
    }
  }
  
  during(0, r, N)
    during(0, c, M)
      A[r][c] = B[r][c];
}

void print_island() {
  //cout << I << endl;
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
      D[r][c] = INT_MAX;
    }
  }

  during(0, i, I) {
    vector<pair<int, int> > island = islands.at(i);
    cout << endl << "island : " << i << endl;
    during(0, p, island.size()) {
      pair<int, int> point = island.at(p);
      //cout << "Point : " << point.first << ", " << point.second << " : ";
      during(0, x, 4) {
        int r = point.first; int c = point.second; int d = 0;
        while(true) {
          if (A[r+dr[x]][c+dc[x]]==1) {
            if (d==0) break;

            pair<int, int> extend = make_pair(r+dr[x], c+dc[x]);
            if (find(island.begin(), island.end(), extend) != island.end()) break;
            during(0, ii, I) {
              if (i == ii) continue;
              //cout << " : Matching " << ii; 
              vector<pair<int, int> > target = islands.at(ii);
              if(d < D[i][ii] && find(target.begin(), target.end(), extend) != target.end()) {
                  D[i][ii] = d;
                  D[ii][i] = d;
                  cout << "Found : " << i << " to " << ii << " : " << point.first << ", " << point.second << " : " << extend.first << ", " << extend.second << " d : " << d << "\n";
              }
            }
          }
          if (!(range(0, r+dr[x], N))) break;
          if (!(range(0, c+dc[x], M))) break;
          r += dr[x];
          c += dc[x];
          d ++;
        }
        //cout << "(" << r << ", " << c << ", "<< d <<"), ";
        
        if (d == 0 || d == 1) continue; 

      }
      //cout << endl;
    }
  }
}

void print_distance_matrix() {
  for (int n = 0 ; n < I; n++) {
    for (int m = 0 ; m < I ; m++) {
      cout << D[n][m] << " ";
    }
    cout << "\n";
  }
}

int prim() {
  bool T[6] = {false, };
  T[0] = 1;
  //cout << "0 ";

  int ans = 0;
  during(1, loop, I) {
    // find min edge from all T
    int min = INT_MAX;
    int min_idx;
    during(0, island, I) {
      // all in T
      if (T[island]) {
        during(0, target, I) {
          // all not in T
          if (!T[target]) {
            if (D[island][target] < min && D[island][target] > 1){
              min = D[island][target];
              min_idx = target;
            }
          }
        }
      }
    }
    
    if (min != INT_MAX){
      ans += min;
      T[min_idx] = true;
    } else{ 
      return -1;
    }

    //cout << min_idx << "(" <<min << ") ";
  }
  if (ans == 0) 
    return -1;
  else {
    for (int i = 0 ; i < I; i++)
      if (!T[i]) return -1;
    return ans;
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  read();
  //print_array();
  find_island();
  //print_island();
  get_distance_matrix();
  //print_distance_matrix();
  cout << prim() << endl;
  return 0;
}
