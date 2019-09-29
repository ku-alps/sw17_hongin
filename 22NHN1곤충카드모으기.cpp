#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int N;
string input;
vector<string> name;
vector<int> num;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  cin >> N;
  for (int i = 0 ; i < N ; i++) {
    cin >> input;
    auto it = find(name.begin(), name.end(), input);
    if (it != name.end()) {
      int idx = distance(name.begin(), it);
      num.at(idx)++;
    } else {
      name.push_back(input);
      num.push_back(1);
    }
  }

  for (int i = 0 ; i < name.size() ; i++) {
    cout << name.at(i);
    cout << " " << num.at(i) << endl;
  }

  int count[1000];
  for (int i = 0 ; i < 1000; i++)
    count[i] = 0;
  for (int i = 0 ; i < num.size() ; i++)
    count[num.at(i)]++;

  vector<int> kind;
  for (int i = 0 ; i < 1000; i++)
    if (count[i]>0)
      kind.push_back(count[i]);

  cout << "kind " ;
  for (int i = 0 ; i < kind.size(); i++)
    cout << kind.at(i) << " ";
  cout << endl;
  
  if (kind.size() > 2)
    cout << "N\n" << N << "\n" << name.size() << "\n";
  else if (kind.size() == 2 && kind.at(0) > 1)
    cout << "N\n" << N << "\n" << name.size() << "\n";
  else if (kind.size() == 2)
    cout << "Y\n" << N+1 << "\n" << name.size() << "\n";
  else if (kind.size() == 1)
    cout << "Y\n" << N << "\n" << name.size() << "\n";
  
  return 0;
}
