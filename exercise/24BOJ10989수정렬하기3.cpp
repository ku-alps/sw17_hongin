#include<iostream>
using namespace std;

int arr[10000000];
int N;

void swap(int a, int b){
  int t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

void debug(int s, int l, int r) {
  for (int i= 0 ; i < N; i++)
    cout << arr[i];
  cout << endl;
  for (int i= 0 ; i < N; i++) {
    if (i == s) cout << 's';
    else if (i == l) cout << 'l';
    else if (i == r) cout << 'r';
    else cout << ' ';
  }
  cout << endl;
}

void quicksort(int s, int e){
  cout << s << "," << e << endl;
  if (s == e)
    return;

  // choose pivot
  int p = arr[s];

  int l, r; l = s + 1, r = e;
  debug(s, l, r);
  while(l < r){
    while(arr[l] < p && l < e)
      l++;
    while(arr[r] > p && r > l)
      r--;
    debug(s, l, r);
    swap(l, r);
  }

  swap(s, l);

  // sort all left values smaller than pivot
  quicksort(s, l-1);

  // sort all right smaller than pivot
  if (l < e)
    quicksort(l+1, e);
}


int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0 ; i < N; i++)
    cin >> arr[i];
  quicksort(0, N-1);
  for (int i = 0 ; i < N;i++)
    cout << arr[i] << '\n';
  return 0;
}
