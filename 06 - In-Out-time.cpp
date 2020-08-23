#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
bool vis[MAX];
int timer;
int in[MAX],out[MAX];
void dfs(int node){
	in[node]=timer++;
	vis[node]=true;
	for(auto i:v[node]){
		if(!vis[i]){
			dfs(i);
		}
	}
	out[node]=timer++;
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		v[i].clear();
		in[i]=0;
		out[i]=0;
	}
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	timer=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"Node "<<i<<" : "<<" "<<in[i]<<" "<<out[i]<<endl;
	}
}