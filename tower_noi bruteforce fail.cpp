#include <bits/stdc++.h>
#include <set>
using namespace std;
#define pii pair<int,int>
const int maxn = 20;
int n;
position_x[20];
position_y[20]
int x_max[20];
int x_min[20];
int y_max[20];
int y_min[20];
map<int,int> mp;

int main(){
	cin >> n;
	for(int i =n-1;i>=0;i--){
		cin >> position_x[i];
		mp[position_x[i]] = 1;
	}
	
	int idx=0;
    for (auto &i:mp) i.se = idx++;
    for(int i =n-1;i>=0;i--){
		position_x[i] = mp[position_x[i]];
    }
	mp.clear();
	
	for(int i =n-1;i>=0;i--){
		cin >> position_y[i];
		mp[position_y[i]] = 1;
	}
	
    idx=0;
    for (auto &i:mp) i.se = idx++;
    for(int i =n-1;i>=0;i--) position_y[i] = mp[position_y[i]];
    
    //discretization complete. memset usage unlocked
    
  
    
	int ans = 1e9;
	int locs;
	for(int i =0;i<(1>>n);i++){
		int points = __builtin_popcount(i);
		if(check(i)){
			if(ans > points){
                ans = points; 
                locs = i;
            }
		}
	}
	for(int i=n-1; i>=0;i--){
        if((locs>>i) &1) cout << "1";
        else cout << "0";
    }
}
