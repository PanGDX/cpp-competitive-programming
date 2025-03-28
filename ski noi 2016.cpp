#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define pii pair<int,int>
/*

5 5 
0 5 5 1
3 4 4 3
-2 3 3 2
1 1 4 4
-1 2 3 1
*/


struct data_lol{
    int xi;
    int yi;
    int easiness;
    int score;
};

bool sorter(data_lol i, data_lol j){
    return i.yi < j.yi;
}

//goes from high height to low height btw

int n, h;
vector <pii> adj[10005];
data_lol arr_data[10005];
int dist[10005];//maximise this
const int inf = LLONG_MAX;
bool visited[10005];

bool valid(int xi, int yi, int xj, int yj, int easiness){
    if(xi == xj && yi == yj) return false;
    
    int difficulty = max(abs(xj - xi) , abs(yi - yj));
    if(yi >= yj && difficulty <= easiness) return true;
    
    return false;
}

signed main(){
    
    cin >> n >> h;
    for(int i =0;i<n;i++){
        int xi, yi, score, easiness;
        cin >> xi >> yi >> score >> easiness;
        
        arr_data[i].xi = xi;
        arr_data[i].yi = yi;
        arr_data[i].score = score;
        arr_data[i].easiness = easiness;
    }
    sort(arr_data, arr_data+n, sorter);
    
    
    
    for(int i =0;i<n;i++){
        dist[i] = arr_data[i].score;
        for(int j = 0; j<n;j++){//can move from gate i to j
            if(valid(arr_data[i].xi, arr_data[i].yi ,arr_data[j].xi ,arr_data[j].yi , arr_data[i].easiness)){
                dist[i] = max(dist[i], dist[j] + arr_data[i].score);
                //printf("VALID %lld: %lld (%lld %lld)\n", j,  dist[j], arr_data[j].xi, arr_data[j].yi);
            }
        }
        //printf("AIDS %lld: %lld (%lld %lld)\n", i,  dist[i], arr_data[i].xi, arr_data[i].yi);
    }
    int maxer = 0;
    for(int i =0;i<n;i++){
        maxer = max(maxer, dist[i]); 
    } 
    cout << maxer;
}


