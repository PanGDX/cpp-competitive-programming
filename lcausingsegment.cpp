#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

vector<int> adj[MAX];
int vis[MAX];
int Euler[2 * MAX];
int first_visited[MAX];
int level[2*MAX];
int tree[8*MAX];
int N; 

void add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void eulerTree(int u, int &index, int depth)
{
	vis[u] = 1;
	Euler[index] = u;
	level[index] = depth;
	if(first_visited[u] == -1) first_visited[u] = index;
	index++;
	for (auto it : adj[u]) {
		if (!vis[it]) {
			eulerTree(it, index, depth +1);
			Euler[index] = u;
			level[index] = depth;
			index++;
		}
	}
}

int query(int tree_pos,int cl,int cr,int l,int r) {//treepos, 0 , n-1, left query, right query
    if (l<=cl&&cr<=r) return tree[tree_pos];
    else if(l>cr || cl>r) return -1;//not sure about this condition too
    
    
    int mid=(cl+cr)>>1;
    int q1 = query(tree_pos * 2, cl, mid, l ,r);
    int q2 = query(tree_pos * 2 +1, mid+1, cr, l,r);
    if(q1==-1)return q2;
    else if(q2 == -1) return q1;
    else{
		if(level[q1] < level[q2]) return q1;
		else return q2;
	}
} 

void build(int pos, int start, int end) {
    if (start == end) {
        // Leaf node
        tree[pos] = start;
    } else {
        int mid = (start + end) / 2;
        // Recurse on the left and right children
        build(2*pos, 	start, mid);
        build(2*pos+1, mid+1, end);
        // Update the current node with the minimum of the left and right children
        if(level[tree[2*pos]] < level[tree[2*pos+1]]){
			tree[pos] = tree[2*pos];
		}
		else tree[pos] = tree[2*pos +1];
    }
}

int lca(int u, int v){
	int pos_u = first_visited[u];
	
	int pos_v = first_visited[v];
	int pos_lca = query(1,0,2*(2*N -1), pos_u, pos_v);
	printf("%d %d %d\n", pos_u, pos_v, pos_lca);
	return Euler[pos_lca];
}

int main()
{
	memset(first_visited,-1,sizeof(first_visited));
	memset(Euler,-1,sizeof(Euler));
	memset(level,-1,sizeof(level));
	N = 7;


	add_edge(1, 2);
	add_edge(1,3);
	add_edge(2, 4);
	add_edge(2, 5);
	add_edge(3,6);
	add_edge(3,7);
	int index =0;
	eulerTree(1,index,0);
	cout << "Euler\n";
	for(int i =0;i<N*2-1;i++)printf("%d ", Euler[i]);
	cout << "\nlevel\n";
	for(int i =0;i<N*2-1;i++)printf("%d ", level[i]);
	cout << "\nfirst\n";
	for(int i =0;i<=N;i++)printf("%d ", first_visited[i]);
	cout << "\n";
	
	
	build(1, 0, (2*N -1));
	for(int i =0;i<=2*(N*2-1);i++)printf("%d ", level[tree[i]]);
	cout << "\n";
	
	cout << lca(6,7);
	
	return 0;
}


