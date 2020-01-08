#include <iostream>
using namespace std;

int arr[20][20], dir[1000], ans[1000];
int N, M, X, Y, K;

void print(){
    for (int i = 0 ; i < N; i++){
        for (int j = 0 ; j < M; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

class Dice {
public:
    int u = 0, d = 0, l = 0, r = 0, h = 0, t = 0; // up down left right head tail
    int R, C;
    Dice(int X, int Y) {R = X; C = Y;}
    bool move(int dir){
        if (dir == 1 && C < M - 1)
            return east();
        else if (dir == 2 && C > 0)
            return west();
        else if (dir == 3 && R > 0)
            return north();
        else if (dir == 4 && R < N - 1)
            return south();
        return false;
    }
    bool east() { int x = r; r = u; u = l; l = d; d = x; C += 1; copy(); return true; }
    bool west() { int x = l; l = u; u = r; r = d; d = x; C -= 1; copy(); return true;  }
    bool north() { int x = t; t = u; u = h; h = d; d = x; R -= 1; copy(); return true;  }
    bool south() { int x = h; h = u; u = t; t = d; d = x; R += 1; copy(); return true;  }
    void copy() {
        if (arr[R][C] == 0){
            arr[R][C] = d;
        } else {
            d = arr[R][C];
            arr[R][C] = 0;
        }
    }
};


int main(){
	cin >> N >> M >> X >> Y >> K;
    Dice dice(X, Y);
    for (int i = 0 ; i < N; i++){
        for (int j = 0 ; j < M; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0 ; i < K; i++){
        cin >> dir[i];
    }
    int count = 0;
    for (int i = 0 ; i < K; i++){
        if(dice.move(dir[i]))
            ans[count++] = dice.u;
        cout << "Move " << i << endl;
        print();
        cout << endl;
    }
    for (int i = 0 ; i < count; i++){
        cout << ans[i] << endl;
    }
	return 0;
}
