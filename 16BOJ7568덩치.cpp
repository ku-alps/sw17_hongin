#include <iostream>
#include <vector>
#define W 0
#define H 1
#define loop(i, n) for (int i = 0; i < n; ++i)
using namespace std;


int N;
int arr[200][2];
int cnt[200] = { 0, };
int ans[200] = { 0, };
int lut[200] = { 0, };
vector<int> v[200];

int main(){
    
    cin >> N;
    loop(i, N)
        cin >> arr[i][W] >> arr[i][H];
    loop(i, N){
        loop(j, N){
            if (arr[i][W] < arr[j][W] && arr[i][H] < arr[j][H])
                cnt[i]++;
        }
    }

    loop(i, N){
        cout << cnt[i] + 1 << " ";
    }

    
    return 0;
}
