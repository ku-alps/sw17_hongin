#include <iostream>
#include <cstring>
#define loop(x,n) for(int x = 0; x < n; ++x)
using namespace std;

#define W 1
#define B 0
int board[8][8] = {
    { W, B, W, B, W, B, W, B },
    { B, W, B, W, B, W, B, W },
    { W, B, W, B, W, B, W, B },
    { B, W, B, W, B, W, B, W },
    { W, B, W, B, W, B, W, B },
    { B, W, B, W, B, W, B, W },
    { W, B, W, B, W, B, W, B },
    { B, W, B, W, B, W, B, W }
};

int R, C;
int arr[50][50];

int main(){
    cin >> R >> C;
    loop(i, R){
        string line;
        cin >> line;
        loop(j, C){
            if (line[j] == 'W')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    
    int min = 64;
    loop(r, R-7){
        loop(c, C-7){
            int cnt1 = 0;
            int cnt2 = 0;
            loop(i, 8){
                loop(j, 8){
                    if (arr[r+i][c+j]!=board[i][j])
                        cnt1++;
                    else
                        cnt2++;
                }
            }
            if (cnt1 < min)
                min = cnt1;
            if (cnt2 < min)
                min = cnt2;
        }
    }
    cout << min << endl;
//    loop(i, R){
//        loop(j, C)
//            cout << arr[i][j];
//        cout << endl;
//    }
    
    
    return 0;
}
