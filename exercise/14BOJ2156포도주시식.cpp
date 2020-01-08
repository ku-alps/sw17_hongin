#include <iostream>
using namespace std;

int n, arr[10001], dp[10000][4];

int main(){
    cin >> n;
    
    for (int i = 1 ; i <= n; i++)
        cin >> arr[i];
    
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0;
    
    for (int i = 1 ; i <= n; i++) {
        // XX
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
        // XO
        dp[i][1] = max(dp[i-1][0] + arr[i], dp[i-1][2] + arr[i]);
        // OX
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]);
        // OO
        dp[i][3] = dp[i-1][1] + arr[i];
    }

    cout << max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3])) << endl;
    return 0;
}

//for (int i = 2 ; i <= n + 1; i++)
//cout << arr[i] << "\t";
//cout << endl << endl;
//for (int i = 2 ; i <= n + 1; i++)
//cout << dp[i][0] << "\t";
//cout << endl;
//for (int i = 2 ; i <= n + 1; i++)
//cout << dp[i][1] << "\t";
//cout << endl;
//for (int i = 2 ; i <= n + 1; i++)
//cout << dp[i][2] << "\t";
//cout << endl;
//for (int i = 2 ; i <= n + 1; i++)
//cout << dp[i][3] << "\t";
//cout << endl;
