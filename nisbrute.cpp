
// C++ program to count increasing subsequences
// in an array of digits.
#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000100];
int counter[1000100];
map<int,int> mp;
const int mod = 1e9 + 7;

int countSub(){



	for (int i=0; i<n; i++)
	{

		for (int j=a[i]-1; j>=0; j--)
			counter[a[i]] = ((counter[a[i]] % mod) + (counter[j] %mod))%mod;


		counter[a[i]]++;
	}


	int result = 0;
	for (int i=0; i<=1000; i++)
		result  =((result %mod) + (counter[i] %mod))%mod;

	return result;
}
/***
 20
 1 2 3 4 5 5 5 2 10 11 13 603 591 442 1 3 5 2 5 6 
 **/

int main()
{
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	cout << countSub();
	return 0;
}
