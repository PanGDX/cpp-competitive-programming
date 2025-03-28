/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pq priority_queue


int inf = 0x3F;
const int maxn = 5010;
ll f[maxn][1<<6];
int n,e,m,Q;
int t[maxn];
vector <pii> edge[maxn];
pq <pair<ll, pii> , vector < pair<ll,pii>>, greater<pair<ll,pii> > > q;
ll big;


void dijkstra(){
    memset(f, inf , sizeof(f));
    big = f[0][0];
    for(int i =0;i<m;i++){
        f[t[i]][0] = 0;
        q.push({0, {t[i], 0}});
    }
    while(!q.empty()){
        int u = q.top().second.first;
        int mask = q.top().second.second;
        ll  d = q.top().first;
        q.pop();
        if(f[u][mask] != d) continue;
        for(pii v: edge[u]){
            if(f[v.first][mask] > d + (ll)v.second ){
                f[v.first][mask] = d + (ll)v.second;
                q.push({d + (ll)v.second, {v.first, mask}});
            }
            for(int i =0;i<5;i++){
                if(((mask >> i) & 1) == 0){
                    int nmask = mask|(1<<i);
                    ll tmp = v.second/10*(10-i-1);
                    if(f[v.first][nmask] > d + tmp){
                        f[v.first][nmask] = d+tmp;
                        q.push({d+tmp, {v.first, nmask}});
                    }
                }
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n>> e >> m;
    
    for(int i= 0;i<m;i++) cin >> t[i];
    
    int u,v,c;
    for(int i =0;i<e;i++){
        cin >> u >> v >> c;
        edge[u].push_back(make_pair(v,c));
    }
    cin >> Q;
    
    int starting;
    int ticket_prices[5];
    for(int i =0;i<Q;i++){
        cin >> starting;
        for(int f = 0;f<5;f++){
            cin >> ticket_prices[f];
        }
        dijkstra();
        ll ans = big;
        for(int i =0; i<= (1<<6);i++){
            ll temp_ans = f[starting][i];
            for(int f=0;f<5;f++){
                if(((i >> f) & 1) == 1){
                    if(ticket_prices[f] != -1){
                        temp_ans += ticket_prices[f];
                    }
                }
            }
            printf("A:%d T:%d\n", ans, temp_ans);
            ans = min(ans, temp_ans);
        }
        if(ans == big) cout << "-1\n";
        else cout << ans << "\n";
    }
}
