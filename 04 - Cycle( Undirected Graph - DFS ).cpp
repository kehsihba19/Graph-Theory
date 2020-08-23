#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
bool vis[MAX];
bool check;
void dfs(int node,int parent){
	vis[node]=true;
	for(auto i:v[node]){
		if(!vis[i]){
			dfs(i,node);
		}
		else{
			if(i!=parent){
				check=true;
			}
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		v[i].clear();
	}
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check=false;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,-1);
		}
	}
	cout<<check;
}