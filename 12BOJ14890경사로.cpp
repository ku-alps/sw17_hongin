#include <iostream>
using namespace std;

int N, L;
int arr[100][100];
int linear[100], diff[100];
int answer = 0;

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i < N; i++){
		diff[0] = 0;	
		for (int j = 1; j < N; j++)
			diff[j] = arr[i][j] - arr[i][j-1];
		
		int cnt = 1, lamp = 0;
		bool lamping = false;
		for (int j = 0; j < N; j++) {
			if (diff[j] == 0) {
				cnt++
				if (lamping) {
					diff[j] = -1;
					if (cnt == L)
						lamping = false;
				}
			} else if (diff[j] == 1) {
				if (cnt < L)
					continue;
				cnt = 1, lamp = 0;
			    int	k = j-1;
				while(k >= 0 && lamp != L){
					if(diff[k] == 0){
						lamp++;
						k--;
					} else
						break;	
				}
				if (lamp < L)
					continue;	
			} else if (diff[j] == -1) {
				if (!lamping) {
					cnt = 1;
					diff[j] = -1;
					lamping = true;
				} else 
					continue;
			}
			if (j == N-1 && lamping == false)
				answer++;
		}
	}
	cout << answer;
	return 0;
}
