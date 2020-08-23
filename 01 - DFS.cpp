#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
bool vis[MAX];
void dfs(int node){
	vis[node]=true;
	cout<<node<<" ";
	for(auto i:v[node]){
		if(!vis[i]){
			dfs(i);
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
	cout<<"Using Recursion - "<<endl;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			cout<<endl;
		}
	}
	cout<<"Using Stack - "<<endl;
	for(int i=1;i<=n;i++){
		vis[i]=false;
	}
	stack<int>s;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			s.push(i);
			while(s.size()){
				int node=s.top();
				cout<<node<<" ";
				s.pop();
				vis[node]=1;
				for(auto j:v[node]){
					if(!vis[j]){
						s.push(j);
					}
				}
			}
			cout<<endl;
		}
	}
}