#include <bits/stdc++.h>
using namespace std;


int x_max[1000010];
int x_min[1000010];
pair<int,int> pos[1000010];
queue<int> answer;

int main(){
    memset(x_min, 0x3f, sizeof(x_min));
    int n;
    cin >> n;
    for(int i =0;i<n;i++){
        int x,y;
        cin >> x>>y;
        pos[i] = {x,y};
        
        x_min[y] = min(x_min[y], x);
        x_max[y] = max(x_max[y], x);
    }
    
    for(int i =0;i<n;i++){
        int selected = 0;
        
        int x_pos = pos[i].first;
        int y_pos = pos[i].second;
        if(x_pos == x_max[y_pos] || x_pos == x_min[y_pos]){
            selected = 1;
        }
        answer.push(selected);
    }
    while(!answer.empty()){
        cout << answer.front();
        answer.pop();
    }
}