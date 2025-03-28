#include <bits/stdc++.h>
using namespace std;

deque <int> Q;
int arr[1000100];
/**
8 3
1 3 -1 -3 5 3 6 7
 * **/
int main(){
	int n,k;
	cin >> n >> k;
	for(int i =0;i<n;i++)cin >> arr[i];
	
	for(int i =0;i<k;i++){
		while(!Q.empty() && arr[Q.back()] < arr[i]) Q.pop_back();
		Q.push_back(i);
	}
	
	for(int i = k;i<n;i++){
		cout << arr[Q.front()] << " ";
		
		while(Q.size() > k) Q.pop_front();
		while(!Q.empty() && arr[Q.back()] < arr[i]) Q.pop_back();
		
		Q.push_back(i);
	}
	cout << arr[Q.front()] << " ";
	
}
