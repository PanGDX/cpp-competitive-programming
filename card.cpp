/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <string>
#include <list>
using namespace std;

//https://codebreaker.xyz/problem/card
//what did we learn? just use the fucking cpp stl for competitive programming. IT will bring you very far.


int main(){
    int n,k;
    cin >> n >>k;
    string s;
    cin >> s;
    list <int> lister;
    for(int i =0;i<n;i++) lister.push_back(i);
    for(int i =0;i<s.length();i++){
        if(s[i] == 'A'){
            int val = lister.front();
            lister.push_back(val);
            lister.pop_front();
        }
        if(s[i] == 'B'){

            list<int>::iterator it1;
            it1 = lister.begin();
            advance(it1,1);
            int val = *it1;
            lister.erase(it1);
            lister.push_back(val);
        }
    }
    list<int>::iterator it2;
    it2 = lister.begin();
    advance(it2, k-1);
    cout << *it2 << " ";
    advance(it2, 1);
    cout << *it2 << " ";
    advance(it2, 1);
    cout << *it2;
}