#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
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
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	cout<<"Topological Sorting :"<<endl;
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}
}