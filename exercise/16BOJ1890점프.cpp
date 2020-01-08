#include <iostream>
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

int N;
int arr[100][100];
long dp[100][100] = { 0, };

int main(){
  cin >> N;
  loop(i, N)
    loop(j, N)
      cin >> arr[i][j];
 
  dp[0][0] = 1;
  loop(i, N){
    loop(j, N){
      if (0 < arr[i][j] && i + arr[i][j] < N)
        dp[i + arr[i][j]][j] += dp[i][j];
      if (0 < arr[i][j] && j + arr[i][j] < N)
        dp[i][j + arr[i][j]] += dp[i][j];
    }
  }
  cout << dp[N-1][N-1] << endl;
  return 0;
}
