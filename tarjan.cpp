#include <bits/stdc++.h>
using namespace std;
/**
dfn is an abbreviation for "discovery time". In Tarjan's algorithm, it is a variable used to keep track
*  of the order in which vertices are discovered during a depth-first search (DFS) of a directed graph.

For each vertex u in the graph, the dfn[u] variable stores the time when the vertex was first discovered 
* during the DFS. The discovery time is incremented for each new vertex that is discovered, and it is used
*  in the calculation of the low-link value for each vertex, which is used to identify the strongly connected
*  components (SCCs) in the graph.
**/
  

const int N = 10010;
vector<int> adj[N];
vector<vector<int>> scc;
int dfn[N], low[N], idx=1;
bool onstack[N];

void tarjan(int u){
    static stack<int> st;

    dfn[u]=low[u]=idx++;
    st.push(u);
    onstack[u]=true;
    
    for(auto i:adj[u]){
        if(dfn[i]==-1){
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(onstack[i])
            low[u]=min(low[u],dfn[i]);
    }
    if(dfn[u]==low[u]){
        vector<int> scctem;
        while(1){
            int v=st.top();
            st.pop();
            onstack[v]=false;
            scctem.push_back(v);
            if(u==v)
                break;
        }
        scc.push_back(scctem);
    }
}

int main() {
  int n, m;
  cin >> n >> m;
  memset(dfn, -1, sizeof(dfn));
  
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    if (dfn[i]==-1) {
      tarjan(i);
    }
  }
  for(vector <int> e: scc){
	for(int i:e){
		printf("%d ", i);
	}
	cout << "\n";
  }
  
  return 0;
}

