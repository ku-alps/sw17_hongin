#include <string>
#include <vector>
#include <iostream>

using namespace std;

void show(vector<vector<int>> arr){
    for (int i = 0 ; i < arr.size(); i++){
        for (int j = 0 ; j <arr.size() ; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int>> lock, vector<vector<int>> key, vector<vector<int>> &temp, int lr, int lc) {
    int N = lock.size();
    for (int i = 0 ; i < N; i++){
        vector<int> row;
        for (int j = 0 ; j <N ; j++){
            row.push_back(lock[i][j]);
        }
        temp.push_back(row);
    }
    
    for (int kr = 0 ; kr < key.size() ; kr++){
        for (int kc = 0 ; kc < key.size(); kc++) {
            if (0 <= lr + kr && lr + kr < N && 0 <= lc + kc && lc + kc< N){
                temp[lr+kr][lc+kc] = lock[lr+kr][lc+kc] + key[kr][kc];
            }
        }
    }
}

void rotate(vector<vector<int>> input, vector<vector<int>> &output){
    int n = input.size();
    for (int i = 0 ; i < n; i++){
        vector<int> row;
        for (int j = 0 ; j <n ; j++){
            row.push_back(input[i][j]);
        }
        output.push_back(row);
    }
    for (int i = 0; i < n; i += 1) {
        for (int j = i+1; j < n; j += 1) {
            swap(output[i][j], output[j][i]);
        }
    }
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n/2; j += 1) {
            swap(output[i][j], output[i][n-1-j]);
        }
    }
}

bool one(vector<vector<int>> arr){
    for (int i = 0 ; i < arr.size(); i++){
        for (int j = 0 ; j <arr.size() ; j++){
            if (arr[i][j] != 1)
                return false;
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size(), N = lock.size();
    for (int rotation = 0; rotation < 4; rotation++){
        for (int r = -M + 1; r < N; r++){
            for (int c = -M + 1; c < N; c++){
                vector<vector<int>> temp;
                //cout << "rotation : "<< rotation << ", r : " << r << ", c : " << c << endl;
                add(lock, key, temp, r, c);
                if (one(temp)){
                    return true;
                }
            }
        }
        vector<vector<int>> next_key;
        rotate(key, next_key);
        key = next_key;
    }
    return false;
}
