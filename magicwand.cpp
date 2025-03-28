#include <bits/stdc++.h>
#include <queue>
using namespace std;

int h,w,x,y,t,maxer,miner,  x_pos,y_pos;

int arr[503][503];
queue <pair<int,int>> q;

int move_hori[4] = {0,1,0,-1};
int move_vert[4] = {1,0,-1,0};

int main(){
    cin >>h >> w >> x >> y>> t;
    x--;y--;
    //Each pixel is a value between 0 and 1023 (inclusive).
    
    for(int row = 0; row < h;row++){
        for(int col = 0; col < w ; col ++){
            arr[row][col] = 1023;
        }
    }
    
    maxer = min(1023, arr[x][y] + t);
    miner = max(0, arr[x][y] - t);
    
    for(int row = 0; row < h;row++){
        for(int col = 0; col < w ; col ++){
            if(arr[row][col] <= maxer && arr[row][col] >= miner) arr[row][col] = -1;
            else arr[row][col] = 0;
        }
    }
    
    
    q.push(make_pair(x,y));
    pair <int,int> loc;
    cout << "start\n";
    while(!q.empty()){
        loc = q.front();
        arr[loc.first][loc.second] = 1;
        
        for(int i =0;i<4;i++){
            x_pos = loc.first + move_vert[i]; 
            y_pos = loc.second + move_hori[i];
            
            if(x_pos >= 0 && x_pos <= h && y_pos >= 0 && y_pos <= w){
                if(arr[x_pos][y_pos] == -1) q.push(make_pair(x_pos,y_pos));
            }
        }
        
        cout << "\n";
        for(int row = 0; row < h;row++){
            for(int col = 0; col < w ; col ++) printf("%d",max(arr[row][col], 0));
            printf("\n");
        }
        cout << "\n";
        q.pop();
    }
    
    cout << "end\n";
    for(int row = 0; row < h;row++){
        for(int col = 0; col < w ; col ++) printf("%d",max(arr[row][col], 0));
        printf("\n");
    }
}
