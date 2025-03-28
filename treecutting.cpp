#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,d; //nodes and num of dragonflies
vector<int> adj[100005];
int bugs[100005];
int species[100005];

int homes[100005];
int parents[100005];

void dfs(int current){
	
	//start from node 1

	for(int neigh : adj[current]){
		if(neigh != parents[current]){
			parents[neigh] = current;
			dfs(neigh);
		}
	}
}

int query(int x){
	set <int> species_eaten;
	
	while(x){
		
		if(bugs[x]){
			bugs[x]--;
			species_eaten.insert(species[x]);
		}
		x = parents[x];
	}
	
	return species_eaten.size();
}

int main(){
	cin >> n >> d;
	//parent of node 1 is 0
	for(int i =1;i<=n;i++) cin >> bugs[i];
	for(int i =1;i<=n;i++) cin >> species[i];
	for(int i=1;i<=d;i++) cin >> homes[i];
	for(int i = 0; i<n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	
	for(int i =1;i<=d;i++){
		cout << query(homes[i]) << " ";
	}
}
/**
 * 
 * 
 * **/
