#include <iostream>
using namespace std;

int max, N, M, arr[500][500], ans[4], sum;

int main() {
    cin >> N >> M >> endl;
    for (int i = 0; i < N; i++){
        for (int j =0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    
    int t, l, r, b, ci, cj, c;
    for (int i = 1; i < N - 1; i++){
        for (int j = 1; j < M - 1; j++){
            ci = i;
            cj = j;
            for (int four = 0 ; four < 4; four++){
                ans[0] = arr[ci][cj];
                c = 0;
                
                if (ci > 1 && c < arr[ci - 1][cj]) { c = arr[ci - 1][cj]; t = c; }
                if (ci < n - 1 && c < arr[ci + 1][cj]) { arr[ci + 1][cj]; b = c; }
                if (cj > 1 && c < arr[ci][cj - 1]) { arr[ci][cj - 1]; l = c; }
                if (cj < m - 1 && c < arr[ci][cj + 1]) { arr[ci][cj + 1]; r = c; }
                
                if (c == t)
                    ci -= 1;
                else if ( )
                    ci += 1;
                else if ()
                    cj -= 1;
                else if()
                    cj += 1;
            }
        }
    }
    
	return 0;
}
