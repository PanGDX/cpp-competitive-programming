/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int n,e;

vector<int> adj0[200010];
vector<int> adj1[200010];
int dis[200010][2];
//dis has to be dis[200010][2] cuz of sample case 2 where it goes back to 1


int bfs(int start_val){
    memset(dis, -1 , sizeof(dis));
    queue<pair<int,int>> Q;
    
    dis[0][start_val] = 0;
    Q.push(make_pair(0 , start_val));
    while(not Q.empty()){
	    int cur = Q.front().first; ///choose the node
	    int val = Q.front().second;
	    
	    if(val == 0){
	        //chose from adj0
	        for(int neigh : adj0[cur]){
	    	    if(dis[neigh][1] == -1){ ///unexplored
	    	    	dis[neigh][1] = dis[cur][0] + 1;
	    	    	//movement= dis[neigh];
	    	    	Q.push(make_pair(neigh, 1));
	    	    }
	        }
	    }
	    
	    else{
	        for(int neigh : adj1[cur]){
	    	    if(dis[neigh][0] == -1){ ///unexplored
	    	    	dis[neigh][0] = dis[cur][1] + 1;
	    	    	//movement= dis[neigh];
	    	    	Q.push(make_pair(neigh, 0));
	    	    }
	        }
	    }
	    Q.pop(); ///pop the nodes
    }
    
    if(dis[n-1][0] == -1 && dis[n-1][1] == -1) return -1;
    else if(dis[n-1][0] == -1) return dis[n-1][1];
    else if(dis[n-1][1] == -1) return dis[n-1][0];
    else{
        return min(dis[n-1][0],dis[n-1][1]);
    }
    
}


int main()
{
    
    cin >> n >> e;
    int a,b,c;
    for(int i =0;i<e;i++){
        cin >> a >> b>> c;
        
        if(c == 0){
            adj0[a].push_back(b);
            adj0[b].push_back(a);
        }
        else{
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
    }
    
    //for start node 0;
    int best0 = bfs(0);

    //for start node 1;
    // take value from the distance matrix. -1 is impossible/not visited yet.
    int best1 = bfs(1);


    
    if(best0 == -1 && best1 == -1) cout << -1;
    else if(best0 == -1) cout << best1;
    else if(best1 == -1) cout << best0;
    else{
        cout << min(best0,best1);
    }
    //comepare answer: lower is better, but -1 is the worst.
}



    //printf("lel %d %d\n", best0, best1);
    // cout << "b";
    // for(int i =0;i<n;i++){
    //     printf("%d %d\n", dis[i][0],dis[i][1]);
    // }
    