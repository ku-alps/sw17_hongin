#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int N;
int freq[100];
priority_queue<int> q;

void enqueue(int val){
  freq[val-1]++;
}

void dequeue(){
  int max = 0, idx = -1;
  for (int i = 0 ; i < 100 ; i++)
    if (max < freq[i]){
      max = freq[i];
      idx = i;
    }
  
  if (idx != -1){
    cout << idx+1 << " ";
    freq[idx]--;
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  for (int i = 0 ; i < 100; i++) 
    freq[i]=0;

  cin >> N;
  string cmd;
  int val;

  for (int i = 0 ; i < N ; i++) {
    cin >> cmd;
    if (cmd == "enqueue"){
      cin >> val;
      enqueue(val);
    } else {
      dequeue();
    }
  }

  return 0;
}
