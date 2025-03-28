#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int n,d; //nodes and num of dragonflies
vector<int> adj[100005];
pii bugs[100005];
set <int> species_eaten;
bool visited[10005];
int homes[100005];


int main(){
	cin >> n >> d;
	for(int i =0;i<n;i++) cin >> bugs[i].first;
	for(int i =0;i<n;i++) cin >> bugs[i].second;
	for(int i=0;i<d;i++) cin >> homes[i];
	for(int i = 0; i<n-1;i++){
		int u,v;
		cin >> u >> v;
		
	}
	
}
