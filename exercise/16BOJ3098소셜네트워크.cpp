#include <iostream>
using namespace std;
int arr[50][50] = { 0, };
int N, M, K;

void print(){
    cout << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N ; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    cin >> N >> M;
    int r, c;
    for (int i = 0 ; i < M; i++){
        cin >> r >> c;
        arr[r-1][c-1] = 1;
        arr[c-1][r-1] = 1;
    }
    
    //print();
    
    bool end;
    for (K = 1 ; K < N; K++){
        end = true;
        //for each row
        for ( r = 0 ; r < N; r++){
            // find column
            for (c = 0; c < N; c++){
                // that has value of K
                if (0 < arr[r][c] && arr[r][c] <= K){
                    
                    int k = arr[r][c];
                    int f = c;
                    // and visit the row of the same value
                    for (int fof = 0; fof < N; fof++)
                        // find column having value of K
                        if (fof != r && arr[r][fof] == 0 && 0 < arr[f][fof] && arr[f][fof] <= k){
                            // and update on the base row as next visit
                            arr[r][fof] = K + 1;
                            end = false;
                        }
                }
            }
        }
        //print();
        
        if (end)
            break;
    }
    
    cout << K - 1 << endl;
    for (int k = 2; k <= K; k++){
        int counter = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (arr[i][j] == k)
                    counter ++;
            }
        }
        cout << counter / 2 << endl;
    }
    
    
    return 0;
}
