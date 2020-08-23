#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
bool vis[MAX];
bool rec[MAX];
bool dfs(int node){
	vis[node]=true;
	rec[node]=1;
	for(auto i:v[node]){
		if(!vis[i] and dfs(i)){
			return true;
		}
		else if(rec[i]){
			return true;
		}
	}
	rec[node]=0;
	return false;
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		v[i].clear();
		rec[i]=false;
	}
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	bool check=false;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bool a=dfs(i);
			if(a){
				check=true;
				break;
			}
		}
	}
	if(check){
		cout<<"Cycle in Directed Graph";
	}
	else{
		cout<<"No cycle Found";
	}
}