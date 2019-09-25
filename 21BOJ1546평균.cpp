#include<iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N; 
  cin >> N;
  float score[1000];

  float sum;
  float max = 0;
  for (int i =0; i< N; i++) {
    cin >> score[i];
    if (score[i] > max) max = score[i];
    sum += score[i];
  }
  float s = 0;
  for (int i =0; i< N; i++) {
    score[i] /= max;
    score[i] *= 100;
    s += score[i];
  }
  //cout << ((((float) sum)/max)/N)*100 << '\n';
  cout << s/N << '\n';

  return 0;
}
