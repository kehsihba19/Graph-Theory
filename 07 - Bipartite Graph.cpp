#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
bool vis[MAX];
int col[MAX];
bool dfs(int node,int c){
	vis[node]=true;
	col[node]=c;
	for(auto i:v[node]){
		if(!vis[i]){
			if(dfs(i,c^1)==false){
				return false;
			}
		}
		else{
			if(col[node]!=col[i]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		v[i].clear();
		col[i]=-1;
	}
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bool check=false;;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bool a=dfs(i,0);
			if(a){
				check=true;
				break; 
			}
		}
	}
	if(check){
		cout<<"Bipartite Graph";
	}
	else{
		cout<<"Not Bipartite Graph";
	}
}