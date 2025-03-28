#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

const int MAXN = 5e3 + 5;
const long long INF = 1e15;

void sol1() {
    int N, K;
    cin >> N >> K;

    vector<long long> C(N + 2, 0), S(N + 2, 0);
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i = 1; i <= N; i++) cin >> S[i];

    vector<long long> sum(N + 2);
    for (int i = N; i > 0; i--)
        sum[i] = sum[i + 1] + S[i];

    vector dp(N + 1, vector<long long>(K + 1, -INF));
    for (int i = 0; i <= N; i++) dp[i][0] = 0;

    long long ans = 0;

    vector<long long> diagonalMx(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            diagonalMx[i - j] = max(diagonalMx[i - j], dp[i - 1][j - 1] + sum[i] - (C[i] * C[i - 1]));

            dp[i][j] = max({dp[i][j], dp[i - 1][j], diagonalMx[i - j] - sum[i + 1] - (C[i] * C[i + 1])});

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}

void sol2() {
    int N, K;
    cin >> N >> K;

    vector<long long> C(N + 2, 0), S(N + 2, 0);
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i = 1; i <= N; i++) cin >> S[i];

    long long dp[N + 1][N + 1][3];
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -INF;

    dp[0][0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - (C[i] * C[i - 1]) + S[i]);
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][1] + S[i]);

            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][2]);

            // If we end here, we took the last element too
            dp[i][j][2] = max(dp[i][j][2], dp[i][j - 1][1] - (C[i] * C[i - 1]));
        }
    }

    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans = max({ans, dp[i][j][0], dp[i][j][2]});
        }
    }

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // sol1();
    sol2();
}
