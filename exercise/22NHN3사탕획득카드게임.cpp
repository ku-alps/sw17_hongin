#include<iostream>
#include<vector>
#include<utility>
#include<stdlib.h>
using namespace std;

int N;
int* score;
string str;
char card;
int turn=0;
vector<pair<int, int> > follow;

int main() {
  cin >> N;
  cin.get();
  score = new int[N];

  for (int i = 0 ; i < N; i++)
    score[i] = 0;
  
  vector<int> win;
  do {
    win.clear();
    cin.get(card);

    if (card == 'A')
      win.push_back(turn%N);
    else if (card == 'J') {
      win.push_back((N + turn - 1) % N);
      win.push_back((turn + 1) % N);
    } else if (card == 'Q') {
      for (int i =0 ; i < N; i++) 
        win.push_back(i);
    } else if (card == 'K') {
        char who;
        cin.get();
        cin.get(who);
        follow.push_back(make_pair(turn, who - '0');
    } else if (card == ' ') 
      continue;

    turn = (turn+1) % N;
    
    for (int i = 0 ; i < win.size() ; i++) {
      score[win.at(i)]++;
    }
  } while(card != '\n');

  for (int i = 0 ; i < N; i++)
    cout << score[i] << " ";
  
  return 0;
}
