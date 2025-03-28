#include <bits/stdc++.h>
using namespace std;

int n,p,q;
int arr[2010];
bool valid(int w){
//this is the tough part. using dp to check for validity.
//so i remember that dp[i][j] is defined as the minimum number of large cameras to fill 1...i, such that number 
//of small camera used is <=j
	int dp[n][p+1];
	int pointer_s=0;
	int pointer_l =0;
	for(int i =0;i<n;i++){
		
	
		while(arr[i] - arr[pointer_s] >= w) pointer_s++;
		while(arr[i] - arr[pointer_l] >= 2*w) pointer_l++;
		//pointer_s is the last location a small camera is placed on the array such that all i are civered  
		//similar to pointer_l
		
		for(int j =0;j<=p;j++){
			if(j){
				if(pointer_s ==0)dp[i][j] = 0;//pretty obvious why. if pointer_s = 0, this means that it is reachable
				//using only small cam at arr[0]. so no big cams needed.
				else if(pointer_l==0) dp[i][j] = min(dp[pointer_s-1][j-1], 1);
				//this one is a bit tougher but still fine. question is why dp[pointer_s-1][j-1]?
				// i know it is to compare 0 vs 1, ie the scenario where no big cams are needed vs 1 big cam, but
				//why dp[p_s-1][j-1]-> j-1 means one less small camera. thus, take away one p_s.
				//->this is possible without adding a single big camera using the property of [j]
				//picking dp[ps-1][j-1] would be the equivalent to saying that you pick one more j
				else dp[i][j] = min(dp[pointer_s-1][j-1], dp[pointer_l	 -1 ][j]+1);
				//this one is because:
				// either you pick a large camera -> dp[q][j-1] +1 
				// or you don't -> dp[s][j-1] -> no big camera added
			}
			else{
				if(pointer_l==0) dp[i][j] = 1;//ie zero small cameras, so need 1 big cam
				else dp[i][j] = dp[pointer_l - 1][j] + 1;//ie you NEED to add one l, since there is no small camera
				//and pointer_l != 0-> that means that you can't just place one and be done with it
			}
		}
	}
	//find minimum large cams
	int ans = 1e9;
	for(int i =0;i<=p;i++){
		ans = min(ans, dp[n-1][i]);
	}
	if(ans > q)return false ;//is valid 
	else return true;
	
}

int main(){
	cin >> n >> p >> q;
	for(int i =0;i<n;i++)cin >> arr[i];
	
	if(p+q>=n) {cout <<1; return 0;}
	
	sort(arr, arr+n);
	int l =1, r= 1e9;
	while(r-l>1){
		int mid = (r+l)>>1;
		if(valid(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << r;
}
