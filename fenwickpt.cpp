#include <bits/stdc++.h>
using namespace std;
int lowbit(int x){return x&(-x);}

int n,m;
int arr[100010];
int tree[200010];
void update(int pos, int val){
	pos++;
	while(pos <= n){
		tree[pos] += val;
		pos += lowbit(pos);//jumping to the next range to update it
	}
}
// Returns sum of arr[0..index].
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
4
0 1
0 9
0 9
5 7
 * **/
int main(){
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> arr[i];
		update(i, arr[i]);
	}
	cin >> m;
	for(int i =0;i<m;i++){
			int a,b;
			cin >> a >> b;
			cout << query(b) - query(a-1) << "\n";
			//needs to be query(a-1) or else it includes the element at a into it as well
	}
	
}
