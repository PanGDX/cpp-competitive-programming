#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define int long long int 

int n,q;

bool vis[1000005];
vector <pair<int,int>> adj[50010];
set <int> needed;
vector<int> weighted;
set <pair<int,int>> positions; //the cur node, then the position in the weighted array

void dfs(int cur){
	vis[cur] = true;
	
	for(pair<int,int> neigh : adj[cur]){
		if(not vis[neigh.first]){
		    
		    positions.insert({neigh.first , weighted.size()});
		    weighted.push_back(weighted.back() + neigh.second);
			dfs(neigh.first);
			
		}
	}
}



signed main(){
    cin >> n;
    
    for(int i =1;i<n;i++){
        int u,v,weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    
    int starting_point;
    for(int i =0;i<=n-1;i++){
        if(adj[i].size() == 1){
            starting_point = i;
            break;
        }
    }
    
    positions.insert({starting_point,0});
    weighted.push_back(0);
    dfs(starting_point);
    
    cin >> q;
    for(int i =0;i<q;i++){
        int a;
        
        int closest = 1e9; //min
        int furthest = -1; //max 

        for(int i =0;i<5;i++){
            cin >> a ;
            
            auto iter = positions.lower_bound({a, -1e9});
            if(iter != positions.end() && (*iter).first == a){
                closest = min(closest, (*iter).second);
                furthest = max(furthest, (*iter).second);
            }
        }
        //cur, -inf 
        cout << weighted[furthest] - weighted[closest] << "\n";
        
        /*
        6
2 0 1
2 1 1
1 3 2 
3 5 3 
5 4 2 
2
2 4 3 1 5
0 2 1 3 5
        */
    }
    
}
