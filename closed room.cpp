/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int height, width, k; 
int loch,locw;

int adj[801][801];
int dis[801][801];


int minimum_val(int a, int b, int c, int d){
    int a1 = min(a,b);
    int a2 = min(c,d);
    return min(a1,a2);
}


int main()
{
    cin >> height >> width >> k;
    
    char temp;
    for(int i =0;i<height;i++){
        for(int f=0;f<width;f++){
            // 0 is blank. 1 is locked room.
            cin >> temp;
            if(temp == '#') adj[i][f] = 2;
            if(temp == '.') adj[i][f] = 1;
            if(temp == 'S'){
                loch = i; locw= f;
                adj[i][f] = 1;
            }
        }
    }
    

    
    

    //inisde main
    queue<pair<int, int>> Q;
    dis[loch][locw] = 0;
    Q.push(make_pair(loch,locw));
    adj[loch][locw] = -1;
    int min_traverse = minimum_val(loch, locw, height - 1- loch, width-1-locw);
    
    //cout << min_traverse << endl;
    int ans = (ceil(double(min_traverse)/double(k)) + 1);
    //cout << ans << "a" << endl;
    int movementh[4] = {1,0,-1,0};
    int movementw[4] = {0,1,0,-1};
    
    
    while(not Q.empty()){
	    int h = Q.front().first;
	    int w = Q.front().second;///choose the node

	    for(int i=0 ; i<4;i++){
	        int newH = h + movementh[i];
	        int newW = w + movementw[i];
	        
	        
	        if(adj[newH][newW] == 1){//valid to move
                dis[newH][newW] = dis[h][w] + 1;
                adj[newH][newW] = -1; //explored
                int max_movement = dis[newH][newW];
                
                int minimum_movement = minimum_val(newH, newW, height - 1- newH, width-1-newW);
                int potential_ans = (ceil(double(max_movement)/double(k)) + ceil(double(minimum_movement)/double(k)));
                //printf("a%d %d %d\n", potential_ans, minimum_movement, max_movement);
                //printf("b%d %d %d\n", potential_ans, newH, newW);
                if(potential_ans < ans) ans = potential_ans;
                
                //cout << "adding" << newH << " " << newW << endl;
                Q.push(make_pair(newH,newW));
	        }
	        
	    }
	    
	    //cout << "deleting" << h << " " << w << endl;
	    Q.pop(); ///pop the nodes
    }
    
    
    //cout << 'h';
    cout << ans;//for some reason, not printing for when ans is not obtained from loop, obtained ie
/*
3 3 3
##.
.S#
###

*/
    
}
