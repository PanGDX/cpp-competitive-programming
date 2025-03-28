#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5;
int LN;
vector<int> adj[nmax];
int dp[nmax][17];
int level[nmax];


void dfs(int u, int p){
	//fill dp table using dfs
	level[u] = level[p] +1;
	dp[u][0] = p; //the parent of u, at (layer?) 0 is p
	for(int i =0;i<LN;i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];//how the fuck does this jump work?
	}
	for(int i =0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(v == p) continue;//do not go if it is the parent
		dfs(v,u);//jump to v, with u as parent
	}
}

int lca(int u, int v){
	//get to the same level
	if(level[u] < level[v]){
		swap(u,v);//level[u] >= level[v] only pls, ie u is 'deeper' in the tree
	}
	int dif = level[u] - level[v];
	for(int i =0;i<LN;++i){
		if((1<<i) & dif){//accessing the 1s and 0s, starting from the (back?)
			u = dp[u][i];//jump? how does this work?
		}
	}//this brings u and v to the same level, somehow
	
	if(u == v) return u; //found parent, ie v is parent of u;
	//find ancestors 
	for(int i =LN-1;i>=0;--i){
		if(dp[u][i] != dp[v][i]){
			u = dp[u][i];
			v = dp[u][i];
		}
	}
	return dp[u][0];
}

int main(){
	int n,m;
	cin >> n >> m;//n-1 vertices, m queries 
	for(int i =0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i =0;i<m;i++){
		int u,v;
		cin>> u >> v;
		cout << lca(u,v) << "\n";
	}
}
