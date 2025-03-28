#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define pii pair<int,int>
/*
The first line of input will contain four integers: R, the number of rows, C, the number of
columns, D, the maximum distance between a sprinkler and a watered mushroom, and K, the
minimum number of sprinklers required for a mushroom to be harvestable
*/
int r,c,d,k;


int main(){
    cin >> r >> c>> d >> k;
    int prefix_sprinkler[r + 10][c + 10];
    for(int i =0;i<=r+10;i++){
        for(int f=0;f<=c+10;f++){
            prefix_sprinkler[i][f] = 0;
        }
    }
    
    vector <pii> coordinates_mushroom;
    
    for(int i =1;i<=r;i++){
        for(int f = 1;f<=c;f++){
            char ct;
            cin >> ct;
            
            prefix_sprinkler[i][f] = prefix_sprinkler[i][f-1] + prefix_sprinkler[i-1][f] - prefix_sprinkler[i-1][f-1];
            
            if(ct == 'M'){
                coordinates_mushroom.push_back({i,f});
            }
            if(ct == 'S'){
                prefix_sprinkler[i][f]++;
            }
        }
    }
    
    // for(int i =1;i<=r;i++){
    //     for(int f = 1;f<=c;f++){
    //         printf("%d ",prefix_sprinkler[i][f] );
    //     }
    //     cout << "\n";
    // }
    
    int ans = 0;
    for(pii e: coordinates_mushroom){
        // use d 
        //e.first -> x
        //e.second -> y
        
        int upper_edge_x = max(e.first - d, 1);
        int upper_edge_y = max(e.second - d, 1);
        
        int lower_edge_x = min(e.first + d, r);
        int lower_edge_y = min(e.second + d, c);
        
        int number_of_sprinklers = prefix_sprinkler[lower_edge_x][lower_edge_y]; 
        number_of_sprinklers-= prefix_sprinkler[upper_edge_x - 1][lower_edge_y]; 
        number_of_sprinklers-= prefix_sprinkler[lower_edge_x][upper_edge_y - 1];
        number_of_sprinklers+= prefix_sprinkler[upper_edge_x - 1][upper_edge_y - 1];
        
        // printf("NO: %d X: (%d %d) (%d %d) (%d %d)\n", number_of_sprinklers, e.first, e.second, upper_edge_x, upper_edge_y, lower_edge_x ,lower_edge_y);
        // printf("%d %d %d %d\n",  prefix_sprinkler[lower_edge_x][lower_edge_y], prefix_sprinkler[upper_edge_x - 1][lower_edge_y], prefix_sprinkler[lower_edge_x][upper_edge_y - 1], prefix_sprinkler[upper_edge_x - 1][upper_edge_y - 1]);
        if(number_of_sprinklers >= k) ans++;
    }
    cout << ans;
}