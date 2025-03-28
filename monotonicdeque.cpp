//For deque
//A monotonic deque is a data structure that allows for efficient insertion and 
//deletion of elements at both ends of the deque (double-ended queue) while maintaining 
//the property of monotonicity. This means that the elements in the deque are either
 //strictly increasing or strictly decreasing.
//often useful for LIS and sliding window maximum/minimum

//the below code is for sliding window maximum/minimum in O(N)
//the question is basically: given an array size n, a window size k, print all max 
//as window moves one index at a time
//deque in this case stores position, and the first element is the largest

#include <bits/stdc++.h>
using namespace std;

deque <int> Q;
int arr[1000100];
/**
8 3
1 3 -1 -3 5 3 6 7
* 
10 3 
5 3 7 2 8 4 2 3 1 0
 * **/
int main(){
	int n,k;
	cin >> n >> k;
	for(int i =0;i<n;i++)cin >> arr[i];
	
	for(int i =0;i<k;i++){
		while(!Q.empty() && arr[Q.back()] > arr[i]) Q.pop_back();
		Q.push_back(i);
	}
	
	for(int i = k;i<n;i++){
		cout << Q.front() << " ";
		
		while(!Q.empty() && Q.front() <= i-k) Q.pop_front();
		while(!Q.empty() && arr[Q.back()] > arr[i]) Q.pop_back();
		
		Q.push_back(i);
	}
	cout <<Q.front() << " ";
	
}
