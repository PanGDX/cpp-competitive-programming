#include<bits/stdc++.h>
using namespace std;
int lowbit(int x) {return x&(-x);}


const int maxn = 1000100;
const int mod = 1e9 + 7;

vector<int> vec;
int n;
int a[1000100];
int counter[1000100];
int tree[2000100];

void update(int pos, int val){
    while(pos <= n){
        tree[pos] = (tree[pos] + val) %mod;
        pos += lowbit(pos);//jumping to the next range to update it
    }
}
// Returns sum of arr[0..index].
int query(int pos){
    int ret = 0;
    while(pos>0){
        ret = (ret +  tree[pos]) %mod;
        pos -= lowbit(pos);
    }
    return ret;
}

signed main()
{
    
    memset(counter, 0, sizeof(counter));
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
        vec.push_back(a[i]);
    }
    
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    
    for(int i =0;i<n;i++){
        a[i] = upper_bound(vec.begin(),vec.end(),a[i])-vec.begin();
    }
    
    for(int i =0;i<n;i++){
        int prev = counter[a[i]];
        int tmp = query(a[i]-1);
        tmp++; tmp%=mod;
        counter[a[i]] += tmp;
        counter[a[i]] %= mod;
        update(a[i] , tmp);//pos val, incremental update
    }
    int sum = 0;
    for(int i =1;i<=n;i++){
        //printf("%d ", counter[i]);
        sum = (sum + counter[i])%mod;
    }
    //cout << endl;
    printf("%d",sum);
    return 0;
    
    
}
