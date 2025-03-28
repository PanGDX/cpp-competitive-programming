#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int n,k;
pii arr[100010];
int main(){
	cin >> n >>k;
	for(int i =0;i<n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
}
/**
 * The DP idea is very standard: let f[i] be the maximum length of
 *  jumps using pillars from [1..i], ending at i. Then f[i] = max of f[j] + 1, for all j 
 * such that |hi−hj|≥d. Then what's left is to find an efficient way to find those j that satisfies 
 * the requirement, and at the same time, find the maximum f[j] amongst 
 * all such j. This is where the segment tree comes in.
 * 
 * **/
