#include <bits/stdc++.h>
using namespace std;
//The first line of the input contains a single integer t (1 ≤ t ≤ 40910) — the number of values n, m and k to process.

//Each of the next t lines contains three integers n, m and k (1 ≤ n, m ≤ 30, 1 ≤ k ≤ min(n·m, 50)) — 
//the dimensions of the chocolate bar and the number of squares you want to eat respectively.

int dp[31][31][51];

int calculate(int n , int m, int k){
	if(dp[n][m][k]||n*m==k||!k) return dp[n][m][k];
	else if( n * m < k) return 1e9;
	else{
		int ret = 1e9;
		
		for(int i =1; i<n;++i){
			for(int j=0;j<=k;j++){
				ret = min(ret, m * m + calculate(i,m,k-j) + calculate(n-i, m, j));
			}
		}
		for(int i = 1;i<m;++i){
			for(int j=0;j<=k;j++){
				ret = min(ret, n * n + calculate(n,i,k-j) + calculate(n, m-i, j));
			}
		}
		
		dp[n][m][k] = ret;
		return ret;
	}
}
//if k =0-> return 0
//if n*m < k -> impossible -> -1
//if n*m == k -> return 0
//if n*m > k

int main(){
	
	int t;
	cin >> t;
	for(int i =0;i<t;i++){
		int n,m,k;
		cin >> n >> m >> k;
		cout << calculate(n,m,k) << "\n";
	}

}
