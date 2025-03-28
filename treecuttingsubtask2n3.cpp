#include <bits/stdc++.h>
using namespace std;

const int n_max = 3e5+10;
vector<int> adj[n_max];

bitset <n_max> banned;

int diameter(int n, int x) {
    queue<int> q;
    vector<int> ans(n, -1);
    ans[x] = 0;
    int biggest = x;
    q.push(x);
    while(q.size()) {
        int next = q.front();
        q.pop();
        for(int i: adj[next]) {
            if(ans[i] == -1 && !banned[i]) {
                ans[i] = ans[next] + 1;
                if(ans[i] > ans[biggest]) {
                    biggest = i;
                }
                q.push(i);
            }
        }
    }
    x = biggest;
    assert(q.empty()); //check actually empty
    ans = vector<int>(n, -1); //start declaring again
    ans[x] = 0;
    biggest = x;
    q.push(x);
    while(q.size()) {
        int next = q.front();
        q.pop();
        for(int i: adj[next]) {
            if(ans[i] == -1 && (!banned[i] || !banned[next])) {
                ans[i] = ans[next] + 1;
                if(ans[i] > ans[biggest]) {
                    biggest = i;
                }
                q.push(i);
            }
        }
    }//repeat bfs
    return ans[biggest];
}

int main(){
	int n;
	cin >> n;
	for(int i =0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		v--,u--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for(int i =0;i<n;i++){
		for(int j: adj[i]){
			banned[i] = true;
			banned[j] = true;
			
			ans = max(ans, diameter(n, i) + diameter(n, j) + 1);
			
			banned[i] = false;
			banned[j] = false;
		}
	}
	cout << ans;
}
