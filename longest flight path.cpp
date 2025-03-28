#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//BFS
int n,m; // number of vertices
vector<int> adj[100005]; // adjacency list of graph
map <int, vector<int>> mapper;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

bool check_connected(int start, int check){
    //a
    for(int u: mapper[start]){ //all these are numbers, not positions btw
        if(check == u) return true;
    }
    return false;
}

int main(){
    cin >> n >> m; 
    int a,b;
    for(int i =0;i<m;i++){
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b); //only one way, so dont add the other side
        mapper[a].push_back(b);
        // a goes to b.
    }
    topological_sort();
    
    
    int whereisone;
    for(int i =0;i<n;i++) if(ans[i] == 0) whereisone = i;  
    
    int answer = 1;
    int prev= whereisone;
    vector <int> stacker;
    stacker.push_back(1);
    
    for(int i = whereisone+1;i<n;i++){//start, check
        if(check_connected(ans[prev], ans[i])){
            prev = i;
            answer++;
            stacker.push_back(ans[i] + 1);
        }
    }
    if(stacker[stacker.size() - 1] == n){
        cout << answer << "\n";
        for(int a : stacker) printf("%d ", a);
    }
    else cout << "IMPOSSIBLE";
}









