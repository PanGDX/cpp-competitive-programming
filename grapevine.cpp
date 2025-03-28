#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n,q;
int weighted[2010][2010];
int soaked[2010];
int visited[2010];
int answer;

void dfs(int start, int distance){
	visited[start] = true;
	
	if(soaked[start] == 1){
		if(answer==-1) answer = distance;
		else {
			answer = min(answer, distance);
		}
		
		//printf("MIN: %lld DIS: %lld\n", answer, distance); 
	}
	
	for (int i = 1; i <= n; i++) {
		if (weighted[start][i] != -1 && (!visited[i])) {
			dfs(i, distance + weighted[start][i]);
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(weighted, -1, sizeof(weighted));
	
	cin >> n >> q;
	for(int i =0;i<n-1;i++){
		int u,v, weight;
		cin >> u >> v >> weight;
		weighted[u][v] = weight;
		weighted[v][u] = weight;
	}
	for(int i=0;i<q;i++){
		int type;
		cin >> type;
		if(type == 1){
			int joint;
			cin >> joint;
			answer = -1;
			memset(visited, false, sizeof(visited));
			dfs(joint, 0);	
			cout << answer << "\n";
		//seek, distance
		}
		else if(type == 2){
			int u;
			cin >> u;
			if(soaked[u] == 1) soaked[u] = 0;
			else soaked[u] = 1;
		//soak
		}
		else{
			int u,v, weight;
			cin >> u >> v >> weight;
			weighted[u][v] = weight;
			weighted[v][u] = weight;	
		//anneal weight
		}
	}
}
