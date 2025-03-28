#include <bits/stdc++.h>
#include <set>
using namespace std;

int n,num;

int main(){
	cin >> n >> num;
	for(int i =n;i>=0;i--){
		if((num >> i) & 1) cout << "1";
		else cout << "0";
	}
}
