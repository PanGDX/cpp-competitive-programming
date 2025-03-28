#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5;
int LN=17;
vector<int> adj[nmax];
int dp[nmax][17];
int level[nmax];


void dfs(int u, int p) {
    level[u] = level[p] + 1;
    dp[u][0] = p;
    for(int i=1; i<LN; ++i)
        dp[u][i] = dp[dp[u][i-1]][i-1];
    for(int i=0; i<adj[u].size(); ++i) {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v, u);
    }
}
 
int lca(int u, int v) {
    if(level[u] < level[v])
        swap(u, v);
    int diff = level[u] - level[v];
    for(int i=0; i<LN; ++i) {
        if((1<<i) & diff)
            u = dp[u][i];
    }
    if(u == v)
        return u;
    for(int i=LN-1; i>=0; --i) {
        if(dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
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
