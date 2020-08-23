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
		v[b].push_back(a);
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			q.push(i);
			vis[i]=1;
			while(q.size()){
				int node=q.front();
				q.pop();
				cout<<node<<" ";
				for(auto j:v[node]){
					if(!vis[j]){
						q.push(j);
						vis[j]=1;
					}
				}
			}
			cout<<endl;
		}
	}
}