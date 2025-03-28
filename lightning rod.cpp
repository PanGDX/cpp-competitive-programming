#include <bits/stdc++.h>
using namespace std;
/*
https://codebreaker.xyz/problem/lightningrod

Note: The input size for subtasks 1, 6 and 7 is extremely large, so it is only possible to obtain
full credit using C++ fast input. The attachment consists of a template that uses C++ fast input
to read from standard input.

*/

inline int readInt() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

int pref[10000000], suff[10000000];

int main(){//X is increasing. Y is random. 
	int N = readInt();

	for(int i = 0; i < N; i++) {
		int x = readInt();
		int y = readInt();
		pref[i] = x+y;
		suff[i] = y-x;
		if(i != 0) pref[i] = max(pref[i], pref[i-1]);
		//in order to ensure that potential points that might fall into the domain of the picked point is included. 
		//since ur only comparing i and i+1, not the whole thing
		// write code here
	}
	
	long long int ans=0;
	for(int i =N-1;i>=0;i--){
	    if(pref[i] > pref[i-1] || i==0){
	        if(i==N-1 || suff[i] > suff[i+1]){
//to ensure not covered. the only way that suff[i] >= suff[i+1] is that the i+1 point has to be above and right,
//such that i falls into the i+1 domain
//if not, so like 7 4 --> -3 compared to 4 3--> -1, 7 4 still does not cover 4 3. but if it is 7 6 or 7 7, then that is a different story
	            ans++;
	        }
	    }
	    //suff is
	    if(i!=N-1)suff[i] = max(suff[i], suff[i+1]);
    //use this condition to do a similar thing like pref[i] = ...
    //it is to ensure that the comparison is not done with the point next to it, but the domain that is covering it, by updating
    //the values for the point that is selected

	}
	cout << ans;
    //using condition:  a lightning rod on building i protects building j if and only if |Xi−Xj | ≤ Yi−Yj .
	// since X is increasing anyways...
	
	
	
	// write code here
	return 0;
}
/*

5
1 1
3 2
4 3
5 3
7 4

with extensive help from the answer key, i think i kinda understand what is going on:
my hypothesis was right. the only way is o(n) and going through the array. However, my implementation is lacking.
Go through the array backwards + pref and suff, storing x+y and y-x. This is after noticing that for the points that
lie on the boundary: 
x+y value is the same
but to the left: y-x stays consant
            right: y-x decreases
            
using these conditions, we can create a specific condition:
ans+=((i==0)||pref[i]>pref[i-1])&&((i==n-1)||suff[i]>suff[i+1]);
*/
