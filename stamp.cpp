#include <bits/stdc++.h>
using namespace std;
#define int long long
int p,s;
int stamps[110];
pair<int,int> dp[110][10010];//stores the number of stamps needed to get this value. min

signed main(){
	for(int i =0;i<110;i++)for(int j=0;j<10010;j++) dp[i][j] = {INT_MAX, 0};
	cin >> p >> s;
	
	for(int i =1;i<=s;i++){
		cin >> stamps[i];
		dp[i][stamps[i]].first = 1;
	}
	sort(stamps + 1, stamps+s+1);
	for(int i =1;i<=s;i++){
		dp[i][0].first = 0;
		//empty set
		dp[i][0].second = 1;
	}

	for(int i =1;i<=s;i++){
		for(int cents = 0; cents <= p;cents++){
			if(cents >= stamps[i]){
				if(dp[i-1][cents].first < dp[i][cents - stamps[i]].first + 1){//you don't select it
					dp[i][cents].first = dp[i-1][cents].first;
					//dp[i][cents].second += dp[i-1][cents].second;
				}
				else{//you do select it
					dp[i][cents].first = dp[i][cents - stamps[i]].first + 1;
					//dp[i][cents].second += dp[i][cents - stamps[i]].second;
				}
			}
			else if(dp[i][cents].first == 1e9) dp[i][cents].first = dp[i-1][cents].first;
			
			if(dp[i][cents].first == dp[i-1][cents].first)dp[i][cents].second = dp[i-1][cents].second;
			if(dp[i][cents].first == dp[i][cents - stamps[i]].first + 1)dp[i][cents].second += dp[i][cents - stamps[i]].second;
		}
	}
	int A=1e9;
	for(int i=1;i<=s;i++){
		A = min(dp[i][p].first,A);
	}
	set<int>included;
	for(int i =1;i<=s;i++){
		if(dp[i][p].first == A) included.insert(dp[i][p].second);
		
	}
	
	if(A==INT_MAX) cout << "-1";
	else cout << A << "\n" << included.size();
	
}
