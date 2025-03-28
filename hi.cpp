#include <bits/stdc++.h>
#include <set>
using namespace std;
#define pii pair<int,int>
int n;
pii position[100000];
//__builtin_popcount()
int x_max[1000010];
int x_min[1000010];
int y_max[1000010];
int y_min[1000010];


unordered_map<int,int> hashings;
int most_frequent(vector <int> tower_pos){
    hashings.clear();
    for(int i: tower_pos){
		hashings[i]++;
	}
    
    int max_count = 0;	
    for(auto i: hashings){ // didnt know you could do this lol
        if(max_count < i.second){
            max_count = i.second;
        }
    }
    return max_count;
}

bool check_valid(int num){

   
    vector<int> tower_x_pos;
	vector<int> tower_y_pos;
    for(int i=n; i>=0;i--){//not sure if i-- or i++
         if((num>>i) &1){ // ie selected
             int x_pos = position[i].first;
             int y_pos = position[i].second;
			
			tower_x_pos.push_back(x_pos);
			 tower_y_pos.push_back(y_pos);
			
             x_max[y_pos] = max(x_max[y_pos], x_pos);
             y_max[x_pos] = max(y_max[x_pos], y_pos);
            
             if(x_min[y_pos] == -1) x_min[y_pos] = x_pos;
             else x_min[y_pos] = min(x_min[y_pos], x_pos);
            
             if(y_min[x_pos]== 0-1) y_min[x_pos] = y_pos;
             else y_min[x_pos] = min(y_min[x_pos], y_pos);
        }
    }
    
    int x_repeat = most_frequent(tower_x_pos);
    int y_repeat = most_frequent(tower_y_pos);
    
    printf("Num:%d X:%d Y:%d\n",num ,x_repeat , y_repeat); 
    
    if(x_repeat > 2 || y_repeat > 2) return false;
    
    
    //printf("%d %d\n", num, answer);
    bool valid = true;
    for(int i =0;i<n;i++){
        int x_pos = position[i].first;
        int y_pos = position[i].second;
        //printf("(%d %d) x_min %d x_max %d y_min %d y_max %d\n", x_pos,y_pos,x_min[y_pos], x_max[y_pos], y_min[x_pos], y_max[x_pos]);
        if((x_min[y_pos] <= x_pos && x_pos <=x_max[y_pos] ) || ( y_min[x_pos] <= y_pos && y_pos <= y_max[x_pos])){
            continue;
        }
        else valid = false;
    }
    
    for(int i =0;i<n;i++){
		int x_pos = position[i].first;
        int y_pos = position[i].second;
             
		x_max[y_pos] = -1;
		x_min[y_pos] = -1;
		y_max[x_pos]=-1;
		y_min[x_pos]=-1;
	}
    
    return valid;
    
}


int main(){
	memset(x_max, -1 , sizeof(x_max));
    memset(x_min, -1 , sizeof(x_min));
    memset(y_max, -1 , sizeof(y_max));
    memset(y_min, -1, sizeof(y_min));
    
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> position[n-i-1].first >> position[n-i-1].second;
    }
    //cout << "fuick\n";
    int ans = 1e9;
    int locs;
    for(int i =1; i< (1<<n);i++){
        bool valid = check_valid(i);
        
        int points = __builtin_popcount(i);
        if(valid){
            printf("%d %d\n", points, i);
            if(ans > points){
                ans = points; 
                locs = i;
            }
        }
    }
    cout << locs << "\n";
    for(int i=n-1; i>=0;i--){//not sure if i-- or i++
        if((locs>>i) &1) cout << "1";
        else cout << "0";
    }
}
