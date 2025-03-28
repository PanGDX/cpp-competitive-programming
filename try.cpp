#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, W;

ll weight[102], value[102], dp[102][100004]; // dp[i][j] = value from [1,i], j represents weight cumulated

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen("_input.txt","r",stdin);
//    freopen("_output.txt","w",stdout);
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 100004; j++) {
            dp[i][j] = LLONG_MIN;
        }
    }
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i] >> value[i];
    }
    dp[1][0] = 0;
    dp[1][weight[1]] = value[1];
    ll sol = value[1];
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - weight[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
                continue;
            }
            dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= W; i++) {
        sol = max(sol, dp[N][i]);
    }
    cout << sol;
    return 0;
}
