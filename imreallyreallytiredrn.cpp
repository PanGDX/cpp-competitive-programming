
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

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

int main(){
	vector <int> locs  = {3,1,4,6,1,5,1,3,5,6, 1, 1}; //most common is 1, 5 of them 

	cout << most_frequent(locs);
	int t;
	cin >> t;
}
