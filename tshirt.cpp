/******************************************************************************
https://codeforces.com/contest/1741/problem/A
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int num_x(string s){
    int a= 0;
    for(int i =0;i<s.length();i++) if(s[i] == 'X') a++;
    return a;
}

/*
possibilities:

XL > L and vv 2
L > M > S and vice-versa
XS < S and vv

\if(s1==s2) printf("A=\n");
    else if(c1 < c2) printf("B>\n");// 76 vs 
    else if(c1>c2)printf("C<\n");
    else if(c1 == 76){
        if(n1>n2) printf("D>\n");
        else printf("E<\n");
    }
    else{
        if(n1>n2) printf("F<\n");
        else printf("G>\n");
    }
*/
void process(string s1, string s2){
    int n1 = num_x(s1);
    int n2 = num_x(s2);
    
    int c1 = int(s1[s1.length() - 1]);
    int c2 = int(s2[s2.length() - 1]);
    /*
    M --> 77
    L --> 76
    S --> 83
    */
    if(s1==s2) printf("=\n");
    else if(c1 < c2) printf(">\n");// 76 vs 
    else if(c1>c2)printf("<\n");
    else if(c1 == 76){
        if(n1>n2) printf(">\n");
        else printf("<\n");
    }
    else{
        if(n1>n2) printf("<\n");
        else printf(">\n");
    }
}
//c e g

int main(){
    int n;
    cin >> n;
    string s1,s2;
    for(int i =0;i<n;i++){
        cin >> s1>>s2;
        process(s1,s2);
    }
}
