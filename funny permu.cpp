/******************************************************************************
https://codeforces.com/contest/1741/problem/B
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void process(int num){
    //like 5,7,9,11,etc,
    for(int i =0;i<num;i++){
        if(i == num/2) cout << num - i -1 << " ";
        else if (i == (num/2+1)) cout << num - i +1 << " ";
        else cout << num -i << " ";
    }
}


int main(){
    int n;
    cin >> n;
    int a;
    for(int i =0;i<n;i++){
        cin >> a;
        if(a == 3) cout << "-1" << endl;
        else if(a==5) cout << "5 4 1 2 3" << endl;
        else{
            if(a%2 == 0) for(int j=a;j>0;j--) printf("%d ", j);
            else process(a);        
            cout << endl;
        }
    }
}
