#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

vector<int> adj[MAX];
int vis[MAX];
int Euler[2 * MAX];
void add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void eulerTree(int u, int &index)
{
	vis[u] = 1;
	Euler[index] = u;
	index++;
	for (auto it : adj[u]) {
		if (!vis[it]) {
			eulerTree(it, index);
			Euler[index] = u;
			index++;
		}
	}
}

void printEulerTour(int root, int N)
{
	int index = 0;
	eulerTree(root, index);
	for (int i = 0; i < (2*N-1); i++)
		cout << Euler[i] << " ";
}

int main()
{
	int N = 4;

	add_edge(1, 2);
	add_edge(2, 3);
	add_edge(2, 4);
	printEulerTour(1, N);

	return 0;
}
