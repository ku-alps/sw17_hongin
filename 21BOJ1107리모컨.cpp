#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;
int M;
int broken[10];
int digit[6];
int mag;

void digitize(int N){
  int i = 0;
  while(N > 0) {
    digit[i++] = N % 10;
    N /= 10;
  }
  mag = i;
}

void dfs(int N, int depth) {
  if (depth == 0){

  }

  int target = digit[depth];
  int up = target, down = target;
  int approximate;
  while(true) {
    if (find(begin(broken), end(broken), up) != end(broken)){
      approximate = up; 
      break;
    }
    if (find(begin(broken), end(broken), down) != end(broken)){
      approximate = down; 
      break;
    }
    up++;
    down--;
  }
   
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  cin >> N;
  cin >> M;
  for (int i = 0; i<M; i++) 
    cin >> broken[i];

  digitize(N); 
  dfs(N, mag-1);
    
  return 0;
}
