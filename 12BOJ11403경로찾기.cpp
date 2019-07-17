#include <iostream>
using namespace std;

int N, arr[100][100], ans[100][100];
int visited[100], queue[100], t = 0, c = 0;

void init_ans() {
	for (int i = 0 ; i < N; i++){
		for (int j = 0; j < N; j++) {
			ans[i][j] = 0;
		}
	}
}
	
void print_ans() {
	for (int i = 0 ; i < N; i++){
		for (int j = 0; j < N - 1; j++)
			cout << ans[i][j] << " ";
		cout << ans[i][N-1] << endl;
	}
}

void bfs_clear(){
	for (int i = 0 ; i < N ; i++)
		queue[i] = 0;
	for (int i = 0 ; i < N ; i++)
		visited[i] = 0;
	t = 0;
	c = 0;
}

void bfs_row(int index) {
//	cout << "Trying index : " << index << endl;	
	bfs_clear();
	queue[t++] = index;
	
	while(c < t) {
		// pop
		int cur = queue[c++];
//		cout << "Poping out of queue : " << cur << endl;
		if(t!=1){
			ans[index][cur] = 1;
			visited[cur] = 1;
		}
			
		// pushing
		for (int i = 0 ; i < N; i++){
			if (arr[cur][i] == 1) {
				if (visited[i] == 0){
//					cout << "Pushing into queue : " << i << endl;
					queue[t++] = i;
				}
			}
		}
	}
	//print_ans();
}

int main(){
	cin >> N;
	for (int i = 0 ; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	init_ans();

	for (int i = 0 ; i < N ; i++) {
		bfs_row(i);
	}

	print_ans();

	return 0;
}
