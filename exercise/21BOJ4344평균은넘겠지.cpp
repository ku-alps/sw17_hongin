#include<iostream>
#include<iomanip>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  int C;
  cin >> C;

  int N;
  int** arr = new int*[C]; 
  for (int i = 0 ; i < C; i++) {
    cin >> N;
    arr[i] = new int[N];
    int sum = 0;
    for (int j = 0 ; j < N; j++) {
      cin >> arr[i][j];
      sum += arr[i][j];
    }
    float avg = (float) sum / N;
    int cnt = 0;
    for (int j = 0 ; j < N; j++) {
      if (arr[i][j] > avg)
        cnt++;
    }
    float above = (float) (cnt * 100) / N;
    cout << fixed << setprecision(3) << above << "%\n";
  }

  for (int i = 0; i < C; i++)
    delete arr[i];
  delete[] arr;

  return 0;
}
