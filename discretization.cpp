#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define debug(x) cerr<<#x<<"="<<x<<endl
#define pq priority_queue
#define ll long long


const int maxn = 100;

map<int,int> mp;
int n;
int a[maxn];

int main() {
//    freopen("input.txt","r",stdin);    
    std::ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i =0;i<n;i++){
		cin >> a[i];
		mp[a[i]]=1;
	}
    
    int idx=0;
    for (auto &i:mp) i.se = idx++;
    for(int i =0;i<n;i++){
		a[i] = mp[a[i]];
		debug(a[i]);
    }
    return 0;
}



