#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
vector<int>v[MAX];
bool vis[MAX];
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
	int in[n+1]={0};
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			in[j]+=1;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	vector<int>ans;
	int count=0;
	while(q.size()){
		int node=q.front();
		ans.push_back(node);
		q.pop();
		for(auto i:v[node]){
			in[i]-=1;
			if(in[i]==0){
				q.push(i);
			}
		}
		count+=1;
	}
	if(count!=n){
		cout<<"Cycle Found in Directed Graph";
	}
	else{
		cout<<"No cycle found"<<endl<<"Topological Sort is :"<<endl;
		for(auto i:ans){
			cout<<i<<" ";
		}
	}
}