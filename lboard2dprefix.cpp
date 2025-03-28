#include <bits/stdc++.h>
using namespace std;
#define int long long int 
int n,m;
int values[1010][1010];
int prefix[1010][1010];
int temp[1010];
int min_prefix[1010][1010];

int prefix_sum(int lowx, int lowy, int highx, int highy){
	int ans = prefix[highx][highy];
	ans += prefix[lowx-1][lowy-1];
	ans -= prefix[lowx-1][highy];
	ans -= prefix[highx][lowy-1];
	//printf("%d %d %d %d\n", prefix[highx][highy],prefix[lowx-1][lowy-1], prefix[lowx-1][highy], prefix[highx][lowy-1]);
	return ans;
}

signed main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> values[i][j];
		}
	}
	
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] -  prefix[i-1][j-1];
			prefix[i][j] += values[i][j];
		}
	}
	/**
	 * 2 2
8 1
3 4
	 * **/
	int maxer = LLONG_MIN;
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ans = values[i][j];
			
			int horizontal_arm = 0, vertical_arm=0;
			
			
			for(int go_col = 1; go_col < j; go_col++){//fix x
				horizontal_arm = max(horizontal_arm, prefix_sum(i , go_col, i, j-1));
			}
			for(int go_col = m; go_col > j; go_col--){
				horizontal_arm = max(horizontal_arm, prefix_sum(i, j+1, i, go_col));
			}
			
			for(int go_row = 1; go_row < i; go_row++){// fix y
				vertical_arm = max(vertical_arm, prefix_sum( go_row, j, i-1, j));
			}
			for(int go_row = n; go_row > i; go_row--){
				vertical_arm = max(vertical_arm, prefix_sum(i+1, j, go_row, j));
			}
			//printf("%lld %lld %lld %lld %lld %lld %lld\n", i , j, ans, vertical_arm, horizontal_arm, maxer, ans + vertical_arm + horizontal_arm);
			maxer = max(maxer, ans + vertical_arm + horizontal_arm);
		}
	}
		
	cout << maxer;
}
/**
 4 4
 1 1 1 1
 1 2 1 1
 1 1 1 1
 1 1 1 1
**/
