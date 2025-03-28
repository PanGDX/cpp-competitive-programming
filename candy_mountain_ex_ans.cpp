#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> segTree, a, dp;
const int INF = 1e18;
int n, k;

void build(int idx, int l, int r) {
    if (l == r) {
        segTree[idx] = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
 
    segTree[idx] = min(segTree[2 * idx], segTree[2 * idx + 1]);
}

void update(int idx, int l, int r, int x, int u) {
    if (l == r) {
        segTree[idx] = u;
        return;
    }

    int mid = (l + r) / 2;
    if (x <= mid) update(2 * idx, l, mid, x, u);
    else update(2 * idx + 1, mid + 1, r, x, u);

    segTree[idx] = min(segTree[2 * idx], segTree[2 * idx + 1]);
}

int query(int idx, int l, int r, int x, int y) {
    if (x <= l && r <= y) return segTree[idx];
    if (x > r || l > y) return INF;

    int mid = (l + r) / 2;
    return min(query(2 * idx, l, mid, x, y), query(2 * idx + 1, mid + 1, r, x, y));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    a = vector<int>(n);
	dp = vector<int>(n + 1);
    segTree = vector<int>(4 * (n + 1));

    build(1, 0, n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int mn = query(1, 0, n, max(0, i - k), i - 1);
        
        dp[i] = max(a[i - 1], mn);
        update(1, 0, n, i, dp[i]);
        printf("%d %d %d\n", i, dp[i], mn);
        //for(int j=0;j<n;j++) printf("%d ", query(1,0,n, j,j));
        //cout << "A\n";
    }

    int ans = INF;
    for (int i = n - k + 1; i <= n; i++)
        ans = min(ans, dp[i]);
    
    cout << ans << '\n';
}
