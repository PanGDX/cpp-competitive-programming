/******************************************************************************
https://codebreaker.xyz/problem/pilot
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mountains[1000100];
int cruising[1000100];

int n,q;
int main()
{
    cin >> n >>q; //n is num of mountains, q is num of airplanes

    for(int i =0;i<n;i++){
        cin >> mountains[i];
    }
    int cruisingh;
    for(int i =0;i<q;i++){
        //for case 6
        cin >> cruisingh;
        long long int ans = 0;
        long long int temp = 0;
        for(int f=0;f<n;f++){
            if(mountains[f] <= cruisingh){
                temp++;
            }
            else{
                ans += (temp)*(temp+1)/2;
                //cout << "a"<< (temp)*(temp+1)/2 << endl;
                temp = 0;
                
            }
        }
        ans += (temp)*(temp+1)/2;
        
        cout << ans << endl;
    }
    
    
}
