#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
vector<int>rv[MAX];
bool vis[MAX];
stack<int>s;
void dfs(int node){
	vis[node]=true;
	for(auto i:v[node]){
		if(!vis[i]){
			dfs(i);
		}
	}
	s.push(node);
}
void rev_dfs(int node){
	vis[node]=true;
	cout<<node<<" ";
	for(auto i:rv[node]){
		if(!vis[i]){
			rev_dfs(i);
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		v[i].clear();
		rv[i].clear();
	}
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	//Step 1: Simple Sort and Topological Sort
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	//Step 2: Reverse all the edges
	for(int i=1;i<=n;i++){
		vis[i]=0;
		for(auto j:v[i]){
			rv[j].push_back(i);
		}
	}
	//Step 3: In the top sorted order dfs
	cout<<"Strongly Connected Components are :"<<endl;
	while(s.size()){
		int node=s.top();
		s.pop();
		if(!vis[node]){
			rev_dfs(node);
			cout<<endl;
		}
	}
	
}