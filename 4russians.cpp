
#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[5010][2];
int c[5010];
int s[5010];
int dp[5010][5010][3];
/**

dp[N][K][3] defined:
for [0]: max if extend by one. 
would be dp[i][j][0] = max(dp[i-1][j-1][0] + s[i] , dp[i][j-1][2] + s[i])?

for [1]: max if stop
dp[i][j][1] = max(dp[i][j][0] - stuff, dp[i][j][1], dp[i][j][2]-stuff)


for [2]: max if new
dp[i][j][2] = max(dp[i][j][0] - stuff, dp[i][j][2], dp[i][j2]


possible moves:
- extend until size k --> add s[i]
- stop existing range --> deduct (ci * ci-1) (back part)
- start new range --> deduct (ci * ci-1) (front part)

 * **/

int main(){
	cin >> n >> k;
	for(int i =0;i<n;i++) cin >> c[i];
	for(int i =0;i<n;i++) cin >> s[i];
	
	
}
