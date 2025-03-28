#include <bits/stdc++.h>
using namespace std;
#define int long long int 
int n,m;
int values[1010][1010];
int prefix_x[1010][1010];
int prefix_y[1010][1010];

int yquery(int start, int end, int col){
	return prefix_y[end][col] - prefix_y[start][col];
}

int xquery(int start, int end, int row){
	return prefix_x[row][end] - prefix_x[row][start];
}

signed main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> values[i][j];
		}
	}
	
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			prefix_x[i][j] = prefix_x[i][j-1] + values[i][j];
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			prefix_y[j][i] = prefix_y[j-1][i] + values[j][i];
		}
	}
	
	
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%lld ", prefix_x[i][j]);
		}
		cout << "\n";
	}
	cout << "\n";
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ", prefix_y[i][j]);
		}
		cout << "\n";
	}
	
	int maxer = LLONG_MIN;
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ans = values[i][j];
			
			int horizontal_arm = 0, vertical_arm=0;
			
			
			for(int go_col = 0; go_col < j; go_col++){//fix row
				printf("A %lld %lld %lld %lld\n", i,j, go_col , xquery(go_col, j-1, i)); 
				horizontal_arm = max(horizontal_arm, xquery(go_col, j, i));
			}
			for(int go_col = n; go_col > j; go_col--){
				printf("B %lld %lld %lld %lld\n", i,j, go_col , xquery(j, go_col, i)); 
				horizontal_arm = max(horizontal_arm, xquery(j, go_col, i));
			}
			
			for(int go_row = 0; go_row < i; go_row++){// fix column
				printf("C %lld %lld %lld %lld\n", i,j, go_row , yquery(go_row , i-1, j)); 
				vertical_arm = max(vertical_arm, yquery(go_row , i, j));
			}
			for(int go_row = m; go_row > i ; go_row--){
				printf("D %lld %lld %lld %lld\n", i,j, go_row , yquery(i ,go_row ,j)); 
				vertical_arm = max(vertical_arm, yquery(i ,go_row ,j));
			}
			printf("%lld %lld %lld %lld %lld %lld %lld\n", i , j, ans, vertical_arm, horizontal_arm, maxer, ans + vertical_arm + horizontal_arm);
			maxer = max(maxer, ans + vertical_arm + horizontal_arm);
		}
	}
	cout << maxer;
}
