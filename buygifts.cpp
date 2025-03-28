#include <bits/stdc++.h>
#include <vector> 
#include <set>
#include <algorithm>
using namespace std;

//https://codebreaker.xyz/problem/buygifts

int n,m;

vector <vector<int>> arr;
/*
Note that if we cannot get joy x, then we cannot get x+1, and if we can get at least x, then we can get at least x−1
.These facts allow us to use binary search to find the answer.

Now we need to understand how exactly we can recognize whether we can gain joy at least x
or not. We can enter at most n−1 shops, so we always need to take two gifts from some store, 
which means there must be a store in which we can find two or more gifts with pleasure at least x. 
Also, each friend should receive a gift, which means that we should be able to buy each gift with pleasure at least x. 
It takes O (nm) to check that both of these conditions are met. The total solution works in O (nm ∗ log (nm)).


So it does not actually matter if you find 3,4,5 etc people in the same shop and/or 3,4,5 shops that the person
can use -> as long as the two conditions above are fulfilled, it works.
*/


bool check(int value){
    bool pair = false;
    vector<bool> able (m);
    
    for(int i =0;i<n;i++){//check for each shop
        int c =0;
        for(int j=0;j<m;j++){//check for each person in each shop
            if(arr[i][j] >= value){
                able[j] = true;//check for the fact that at least one hsop has the value that you want for the person
                c++;
            }
        }
        if(c > 1) pair = true; 
        //this is to check that there is AT LEAST one shop that has more than 1 person.
    }
    
    
    if(!pair) return false;
    bool ans = true;
    for(int i =0;i<m;i++){
        if(!able[i]) ans = false;
    }
    return ans;
}

int main(){
    cin >> n >> m;
    
    arr.assign(n, vector<int>(m));
    
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int l =1,r= 2;
    while(check(r))r*=2;
    
    while(r-l > 1){
        int mid = (r+l)/2;
        if(check(mid)) l =mid;
        else r = mid;
    }
    cout << l;
}