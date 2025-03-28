#include <bits/stdc++.h>
#include <string>
using namespace std;


string s1,s2;
int arr[1005][1005];
int result = 0; 

int commoner()
{
	int m = s1.length();
	int n = s2.length();
	
	for (int i = 1; i <= m; i++)
	{
		for(int j=1;j<=n;j++){
		    if(s1[i-1] == s2[j-1]){
		        arr[i][j] = arr[i-1][j-1] + 1;
		        result = max(result, arr[i][j]);
		    }
		    else{
		       arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
		    }
		}
	}
	return result;
}

int main()
{
    cin >> s1 >> s2;
	cout << commoner();
	cout << "\n";
	int m = s1.length();
	int n = s2.length();
	for (int i = 1; i <= m; i++){
		for(int j=1;j<=n;j++){
		    printf("%d ", arr[i][j]);
		}
		cout << "\n";
	}
	return 0;
}
