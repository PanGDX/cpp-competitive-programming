/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

pair<int,int> price[20100];

bool sorter(pair<int,int> i ,pair<int,int> j){
    return i.first > j.first;
}
//https://codebreaker.xyz/problem/paint
int main()
{
    int n;
    cin >> n;
    for(int i =0;i<n;i++) cin >> price[i].second;
    for(int i =0;i<n;i++) cin >> price[i].first;
    
    sort(price, price+n,sorter);
    long long int ans = 0;
    long long int temp;
    
    //for(int i =0;i<n;i++) printf("%d ", price[i].second);
    
    
    for(int i =0;i<n;i++){
        temp = (price[i].second) + (price[i].first)*i;
        ans += temp;
    }
    cout << ans;
}

/*
7
100 200 500 300 400 200 100
5   2   0   5   7   1   3

7   5   5   3   2   1   0
400 300 100 100 200 200 500

*/