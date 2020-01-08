#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int N,M,tmp;
int Subject[1001];
vector<int>Sub[1001];
vector<int>real_Student[1000];
bool visit[1000][1001];
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++)
		cin>>Subject[i+1];
	for(int i=0;i<N;i++){
		while(1){
			cin>>tmp;
			if(tmp==-1)break;
			Sub[tmp].push_back(i);
		}
	}
	
	for(int i=0;i<M;i++){
		if(Sub[i+1].size()<=Subject[i+1]){
			for(int j=0;j<Sub[i+1].size();j++){
				if(visit[Sub[i+1][j]][i+1])continue;
				real_Student[Sub[i+1][j]].push_back(i+1);
				visit[Sub[i+1][j]][i+1]=true;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		while(1){
			cin>>tmp;
			if(tmp==-1)break;
			Sub[tmp].push_back(i);
		}
	}
	
	for(int i=0;i<M;i++){
		if(Sub[i+1].size()<=Subject[i+1]){
			for(int j=0;j<Sub[i+1].size();j++){
				if(visit[Sub[i+1][j]][i+1])continue;
				real_Student[Sub[i+1][j]].push_back(i+1);
				visit[Sub[i+1][j]][i+1]=true;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(real_Student[i].size()==0)continue;
		sort(real_Student[i].begin(),real_Student[i].end());
	}
	for(int i=0;i<N;i++){
		if(real_Student[i].size()==0)
			cout<<"망했어요"<<endl;
		else{
			for(int j=0;j<real_Student[i].size();j++)
				cout<<real_Student[i][j]<<" ";
			cout<<endl;
			}
	}
	return 0;
}
