#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char A[50], B[50];
    int alen, blen, min = 50;
    
    cin >> A >> B;
    alen = strlen(A);
    blen = strlen(B);
    
    for (int offset = 0; offset <= blen - alen ; offset++){
        int count = 0;
        for (int i = 0; i < alen; i++){
            if (A[i] != B[offset + i])
                count++;
        }
        if (min > count) min = count;
    }
    cout << min;
	return 0;
}
