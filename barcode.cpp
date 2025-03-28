#include <bits/stdc++.h>
using namespace std;


int n,m,x,y;

int arr[1010][1010];

int conversion[1010];//cost of converting alll # -> .
int prefix[1010];
int dp[1010][2];// color of last position

int return_black(int x, int y){
	return prefix[y] - prefix[x-1];
}
int return_white(int x, int y){
	return ((y-x+1)*n) - (prefix[y] - prefix[x-1]);
}


int main(){
	
	cin >> n >> m >> x >> y;
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char s; cin >> s;
			if(s=='.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i =1;i<=n;i++){
			conversion[j] += arr[i][j];
		}
	}
	prefix[0] = 0;
	for(int i =1;i<=m;i++){
		prefix[i] = prefix[i-1] + conversion[i];
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	//white is i=1, black is i=0
	
	//return is inclusive
	
	for(int i =1;i<=m;i++){
		int retb = 1e9;
		int retw = 1e9;
		for(int j=x;j<=y;j++){//convert to black
			if(i>=j){
				retb = min(retb, dp[i-j][1] + return_white(i-j+1,i));
				retw = min(retw, dp[i-j][0] + return_black(i-j+1,i));
			}
		}
		dp[i][0] = retb;
		dp[i][1] = retw;
	}
	cout << min(dp[m][1], dp[m][0]);
}
