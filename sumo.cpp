#include <bits/stdc++.h>
using namespace std;

int N, M, now = 0;

vector <int> adj[100005];

int vertices[300005][2];

int visited[100005];

bool flag = false;

void setup(int round) {
    if (round < now) { // delete shit
        for (int i = round + 1; i <= now; i++) {
            int a = vertices[i][0], b = vertices[i][1];
            auto ita = find(adj[a].begin(),adj[a].end(), b);
            adj[a].erase(ita);
            auto itb = find(adj[b].begin(),adj[b].end(), a);
            adj[b].erase(itb);
        }
        return;
    }
    // add shit
    for (int i = now; i <= round; i++) {
        int a = vertices[i][0], b = vertices[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void bfs(int v) {
    queue <int> Q;
    Q.push(v);
    visited[v] = 1;
    while (not Q.empty()) {
        int cur = Q.front();
        for (int neigh : adj[cur]) {
            if (not visited[neigh]) {
                visited[neigh] = 1 + (visited[cur] % 2);
                Q.push(neigh);
            }
            if (visited[neigh] == visited[cur]) {
                flag = true;
                return;
            }
        }
        Q.pop();
    }
}

bool possible() {
    for (int i = 1; i <= N; i++) {
        if (not visited[i]) {
            bfs(i);
        }
        if (flag) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        vertices[i][0] = a;
        vertices[i][1] = b;
    }
    int lo = 1, hi = M;
    while (hi > lo) {
        int mid = lo + (hi - lo) / 2;
        setup(mid);
        now = mid;
        if (possible()) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
        for (int i = 1; i <= N; i++) {
            visited[i] = 0;
        }
        flag = false;
    }
    cout << lo;
    return 0;
}