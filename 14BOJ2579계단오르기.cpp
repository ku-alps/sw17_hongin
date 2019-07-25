#include <iostream>
using namespace std;

int n, arr[300], dp[301][3];

int main(){
    cin >> n;
    
    for (int i = 1 ; i <= n; i++)
        cin >> arr[i];
    
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0; 
    
    for (int i = 1 ; i <= n; i++) {
        // XO
        dp[i][0] = dp[i-1][1] + arr[i]; // OXO
        // OX
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]); // XOX OOX
        // OO
        dp[i][2] = dp[i-1][0] + arr[i]; // XOO
        
    }
    
    cout << max(dp[n][0], dp[n][2]) << endl;
    return 0;
}
