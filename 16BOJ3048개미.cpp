#include <iostream>
#include <cstring>
#include <vector>
#define RIGHT 0
#define LEFT 1
using namespace std;


class Ants{
public:
    char ch;
    int dir;
};

Ants arr[26];

void swap(int a, int b){
    Ants t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int main(){
    int N1, N2;
    cin >> N1 >> N2;
    string s1, s2;
    cin >> s1 >> s2;
    int T;
    cin >> T;
    

    for(int i = 0 ; i < N1; i++){
        arr[N1 -1 - i].ch = s1[i];
        arr[N1 -1 - i].dir = LEFT;
    }

    for(int i = 0 ; i < N2; i++){
        arr[N1 + i].ch = s2[i];
        arr[N1 + i].dir = RIGHT;
    }
    
    for(int i = 0 ; i < T; i++) {
        for ( int j = 0 ; j < N1 + N2 - 1 ; j++) {
            if (arr[j].dir == LEFT && arr[j+1].dir == RIGHT){
              swap(j, j+1);
              j++;
            }
        }
    }
    for(int i = 0 ; i < N1 + N2; i++){
        cout << arr[i].ch ;
    }
    return 0;
}

