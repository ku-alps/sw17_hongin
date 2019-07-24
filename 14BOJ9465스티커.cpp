#include<iostream>
using namespace std;

int T, n, arr[2][100001], dp_sum[100000], dp_flg[100000], A, ans[100000];

void rcv_dp(int idx){
    if (idx == n+1) {
        if (A < dp_sum[n])
            A = dp_sum[n];
        return;
    }
    
    if (dp_flg[idx-1] == 1 || dp_flg[idx-1] == 2) {
        dp_flg[idx] = 0;
        dp_sum[idx] = dp_sum[idx-1] + arr[0][idx];
        rcv_dp(idx+1);
    }
    
    if (dp_flg[idx-1] == 0 || dp_flg[idx-1] == 2) {
        dp_flg[idx] = 1;
        dp_sum[idx] = dp_sum[idx-1] + arr[1][idx];
        rcv_dp(idx+1);
    }
    
    if (dp_flg[idx-1] == 0 || dp_flg[idx-1] == 1) {
        dp_flg[idx] = 2;
        dp_sum[idx] = dp_sum[idx-1];
        rcv_dp(idx+1);
    }
}
int main() {
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n;
        A = 0;
        dp_flg[0] = 2;
        dp_sum[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> arr[0][i];
        for (int i = 1; i <= n; i++)
            cin >> arr[1][i];
        rcv_dp(1);
        ans[t] = A;
    }
    for (int t = 0; t < T; t++){
        cout << ans[t] << endl;
    }
	return 0;
}
