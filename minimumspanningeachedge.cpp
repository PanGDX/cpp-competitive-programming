#include <bits/stdc++.h>
using namespace std;
#define pii pair <int,int>

int n,m;
vector <pii> adj[200010];

int main(){
	cin >> n >> m;
	for(int i =0;i<m;i++){
		int u,v,weight;
		cin >> u >> v >> weight;
		adj[u].push_back({v,weight})
		adj[v].push_back({u,weight});
	}
}
