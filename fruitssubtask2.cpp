
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n;
int fruit_cost[4000005];
int fixed_allocation[4000005];
int prefix[4000005];

signed main() {
	ios::sync_with_stdio(false);cin.tie();
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> fixed_allocation[i];
	}
	for(int i=1;i<=n;i++){
		cin >> fruit_cost[i];
	}
	for(int i =1;i<=n;i++){
		prefix[i] = prefix[i-1] + fruit_cost[i];
	}
	for(int i =1;i<=n;i++){
		cout << prefix[n] - prefix[n-i] << " ";
	}
	return 0;
}
