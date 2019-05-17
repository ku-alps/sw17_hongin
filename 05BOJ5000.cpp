#include<iostream>
#include <deque>
using namespace std;

void rotate(deque<int*> &seq, int* ind) {
	int temp;
	if (ind >= 2) {
		temp = seq.at(ind)
		seq.at(ind) = seq.at(ind-1)
		seq.at(ind-1) = seq.at(ind-2)
		seq.at(ind-2) = temp
	} else if (ind == 1) {
		temp = seq.at(ind+1)
		seq.at(ind+1 = seq.at(ind)
		seq.at(ind) = seq.at(ind-1)
		seq.at(ind-1) = temp
	} else if (ind == 0) {
		temp = seq.at(ind+2)
		seq.at(ind+2) = seq.at(ind+1)
		seq.at(ind+1) = seq.at(ind)
		seq.at(ind) = temp
	}
}
int main()
{
	deque<int> seq, boss;
	int n, temp;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> temp;
		seq.push_back(temp);
	}
	for (int i = 0 ; i < n ; i++) {
		cin >> temp;
		boss.push_back(temp);
	}
	
	for (int i = 0 ; i < n ; i++) {
		while(seq.front() != boss.at(i)) {
			if (seq.size() >= 3) {
				int i;
				for (i = 0 ; i < n; i++)
					if (seq.at(i) == boss.at(i))
						break;
				rotate(seq, i);
			} else {
				cout << "Impossible";
			}
		}
		seq.pop_front();
	}
	cout << "Possible";	
}
