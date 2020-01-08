#include<iostream>
using namespace std;

int T, n, arr[100001][2], dp[100001][3], ans[100000];

int main() {
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i][0];
        for (int i = 1; i <= n; i++)
            cin >> arr[i][1];
        dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
        for (int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][1] + arr[i][0], dp[i-1][2] + arr[i][0]);
            dp[i][1] = max(dp[i-1][0] + arr[i][1], dp[i-1][2] + arr[i][1]);
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
        }
        ans[t] = max(max(dp[n][0], dp[n][1]), dp[n][2]);
    }
    for (int t = 0; t < T; t++){
        cout << ans[t] << endl;
    }
	return 0;
}
