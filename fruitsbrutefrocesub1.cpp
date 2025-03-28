#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int,int>
#define debug(x) cerr<<#x<<"="<<x<<endl
int n;
pii fruit_cost[4000005];
int fixed_allocation[4000005];

bool checker(){
	bool valid = true;
	for(int i =0;i<n;i++){
		if(fixed_allocation[i] != fruit_cost[i].second && fixed_allocation[i] != -1)valid = false;
	}
	return valid;
}

int totalcostcalc(int sections){
	int ans = 0;
	int greatest_taste = -1;
	for(int i =0;i<=sections;i++){
		if(fruit_cost[i].second > greatest_taste){
			ans += fruit_cost[i].first;
			greatest_taste = fruit_cost[i].second;
		}
	}
	return ans;
}

bool sorter(pii i, pii j){
	return i.second < j.second;
}

signed main() {
	ios::sync_with_stdio(false);cin.tie();
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> fixed_allocation[i];
		if(fixed_allocation[i] != -1)fixed_allocation[i]--;
	}
	for(int i=0;i<n;i++){
		int cost;
		cin >> cost;
		fruit_cost[i] = {cost, i};
	}
	for(int sections= 0;sections<n;sections++){
		int maxcost= 0;
		do{
			//cout << "HI";
			//
			//
			if(checker()){
				//for(int i =0;i<=sections;i++) printf("%lld ", fruit_cost[i].second);
				//debug(totalcostcalc(sections));
				//printf("   Total: %lld\n", totalcostcalc(sections));
				maxcost = max(maxcost, totalcostcalc(sections));
			}
			//check if fixed allocation and permutation adds up
			//if it does, calc. keep track of highest taste and total cost
			//max cost
			
		}while(next_permutation(fruit_cost, fruit_cost+n));
		cout << maxcost << " ";
		sort(fruit_cost, fruit_cost+n, sorter); 
	}
}

/**
 5
-1 3 -1 -1 -1
1 2 2 2 3
0 1 2 3 4
 * **/
