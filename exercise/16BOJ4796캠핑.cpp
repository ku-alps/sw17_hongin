#include <iostream>
using namespace std;

int ans[10000];
int calc(int L, int P, int V){
    int R = V % P;
    return (V / P) * L + (R < L ? R : L);
}

int main(){
    int L, P, V, I = 0;
    while(true){
        cin >> L >> P >> V;
        if (L==0&&P==0&&V==0)
            break;
        ans[I++] = calc(L, P, V);
    }
    
    for (int i = 0 ; i < I; i++){
        cout << "Case " << (i + 1) << ": " << ans[i] << endl;
    }
    return 0;
}
