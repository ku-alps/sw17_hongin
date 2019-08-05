#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void swap(char arr[26], int a, int b){
    char t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int main(){
    int N1, N2, T;
    string s1, s2;
    cin >> N1 >> N2;
    cin >> s1 >> s2;
    cin >> T;
    
    char* arr = new char[N1 + N2];
    for(int i = 0 ; i < N1; i++)
        arr[N1 -1 - i] = s1[i];
    for(int i = 0 ; i < N2; i++)
        arr[N1 + i] = s2[i];
    for(int i = 0 ; i < N1 + N2; i++)
        cout << arr[i] << endl;
    
    return 0;
    
    
    return 0;
}
