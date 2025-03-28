#include <bits/stdc++.h>
using namespace std;
#define int long long int 
int n,days;
int arr[100010];

signed main(){
	cin >> n >> days;
	
	int highest_i=0;
	for(int i =0;i<n;i++){
		cin >> arr[i];
		if(arr[highest_i] < arr[i]) highest_i = i;
	}
	
	int ans=0;
	for(int i =0;i<n;i++){
		if(highest_i == i){
			ans += ((arr[i] + days) * (arr[i]+days));
		}
		else{
			ans += (arr[i] * arr[i]);
		}
	}
	cout << ans;
}
