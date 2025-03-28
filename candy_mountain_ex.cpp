#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr;

vector<int> minimum_range;

void min_void(){
	deque <int> Q;
	for(int i =0;i<k;i++){
		while(!Q.empty() && arr[Q.back()] > arr[i]) Q.pop_back();
		Q.push_back(i);
	}
	
	for(int i = k;i<n;i++){
		minimum_range.push_back(Q.front());
		
		
		while(!Q.empty() && Q.front() <= i-k) Q.pop_front();
		while(!Q.empty() && arr[Q.back()] > arr[i]) Q.pop_back();
		
		Q.push_back(i);
	}
	minimum_range.push_back(Q.front());
	
}
//10 3 5 4 7 2 8 4 2 3 1 0
int main(){
	cin >> n >>k;
	for(int i =0;i<n;i++){
		int a;cin >> a;
		arr.push_back(a);
	}
	reverse(arr.begin(), arr.end());
	min_void();
	int pos = -1;
	int ans_max = 0;
	//for(int i=0;i<arr.size();i++)printf("%d ",arr[i]);
	cout << "\n";
	//for(int i =0;i<minimum_range.size();i++)printf("%d ", minimum_range[i]);
	while(pos + k<n){
		pos++;
		pos = minimum_range[pos];
		
		printf("POS: %d\n", pos);
		ans_max = max(ans_max, arr[pos]); 
	}
	cout << "\n";
	cout << ans_max;
}
