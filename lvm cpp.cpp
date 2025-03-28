/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;

stack <int> stacker;
stack <int> loader;
pair<int,int> commands[1001];
int pointer=0;
int n;

void process(){
    if(commands[pointer].first == 0){
            stacker.push(commands[pointer].second);
            pointer++;
        }
    if(commands[pointer].first == 1){
            int high1 = stacker.top();
            stacker.pop();
            loader.push(high1);
        }
    if(commands[pointer].first == 2){
            int high1 = loader.top();
            loader.pop();
            stacker.push(high1);
        }
    if(commands[pointer].first == 3){
            int high1 = stacker.top();
            stacker.pop();
            int high2 = stacker.top();
            stacker.pop();
            stacker.push(high1 + high2);
            pointer++;
        }
    if(commands[pointer].first == 4){
            int high1 = stacker.top();
            stacker.pop();
            int high2 = stacker.top();
            stacker.pop();
            stacker.push(high1 * high2);
            pointer++;
        }
    if(commands[pointer].first == 5){
            int topper = stacker.top();
            stacker.pop();
            if(topper == 0) pointer = commands[pointer].second;
            else pointer++;
        }
}

int main(){
    //PUSH X  0
    //STORE 1
    //LOAD 2
    //PLUS 3
    //TIMES 4 
    //IFZERO N 5 
    //DONE 6 
    
    
    memset(commands, -1, sizeof(commands));

    cin >> n;
    loader.push(0);
    for(int i =0;i<n;i++){
        string s;
        cin >> s;
        if(s == "PUSH"){
            int temp;
            cin >> temp;
            commands[i].first = 0;
            commands[i].second = temp;
        }
        else if(s=="STORE")commands[i].first = 1;
        else if(s=="LOAD")commands[i].first = 2;
        else if(s=="PLUS")commands[i].first = 3;
        else if(s=="TIMES")commands[i].first = 4;
        else if(s=="IFZERO"){
            int temp;
            cin >> temp;
            commands[i].first = 5;
            commands[i].second = temp;
        }
        else if(s=="DONE")commands[i].first = 6;
    }
    
    //while(commands[pointer].first != 6){
        process();
        //cout << "hi" << flush;
    //}
    cout << stacker.top();
    cout << "hia";
}
/*

14
PUSH 5
STORE
LOAD
LOAD
PUSH -1
PLUS
STORE
LOAD
IFZERO 13
LOAD
TIMES
PUSH 0
IFZERO 3
DONE

*/
