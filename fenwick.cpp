//modify into difference between elements first.
#include <bits/stdc++.h>
using namespace std;
int lowbit(int x){return x&(-x);}

int n,m;
int arr[100010];
int dif[100010];
int tree[200010];
void update(int pos, int val){
	pos++;
	while(pos <= n){
		tree[pos] += val;
		pos += lowbit(pos);//jumping to the next range to update it
	}
}
// Returns sum of arr[0..index].

void range_update(int l, int r, int val){
	update(l,val);
	update(r+1, -val);
}

int query(int pos){
	int ret = 0;
	pos++;
	while(pos>0){
		ret+= tree[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

/**

10
1 2 9 5 7 6 3 4 2 2
10
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0
1
0
5

5 3 -> becomes:
1 2 9 5 7 9 6 7 5 5
 * **/
int main(){
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> arr[i];
		//update(i, arr[i]);
	}
	for(int i =0;i<n;i++){
		dif[i] = arr[i] - arr[i-1];
		update(i, dif[i]);
	}
	cin >> m;
	
	for(int i =0;i<m;i++){
		int a;
		cin >> a;
		printf("A:%d: %d\n", i, query(a));
	}
	range_update(1,3, 2);
	for(int i =0;i<m;i++){
		int a;
		cin >> a;
		printf("B:%d: %d\n", i, query(a));
	}
}
