
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//define int long long int
#define pii pair<int, int>


int n,e;
vector <pii> arr[ 100005];
int dist[100005];


const int INF = 1e9;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    
    int a,b,c;
    for(int i =0;i<e;i++){
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b,c));
        arr[b].push_back(make_pair(a,c));
    }
    
    for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int u = arr[j].u;
			int v = arr[j].v;
			int w = arr[j].w;
			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}
	if(dist[n] == INF) cout << "-1"
	else cout << dist[n];
}
