/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int h,w;
int arr[505][505];
//int dynamic_arr[505][505];
int temp1,temp2,temp3,ans;
int move[3] = {-1,0,1};


void form_arr(int row){
    if(row == -1) return;
    
    
    for(int i =0;i<w;i++){
        if(i == 0){
            temp1 = arr[row][i] + arr[row+1][i];
            temp2 = arr[row][i] + arr[row+1][i+1];
            arr[row][i] = max(temp1, temp2);
        }
        else if(i == w-1){
            temp1 = arr[row][i] + arr[row+1][i];
            temp2 = arr[row][i] + arr[row+1][i-1];
            arr[row][i] = max(temp1, temp2);
        }
        else{
            temp1 = arr[row][i] + arr[row+1][i];
            temp2 = arr[row][i] + arr[row+1][i+1];
            temp3 = arr[row][i] + arr[row+1][i-1];
            ans = max(temp1,temp2);
            arr[row][i] = max(ans, temp3);
        }
    }
    
    form_arr(row - 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> h >> w;
    for(int i =0;i<h;i++){
        for(int j =0;j<w;j++) cin >> arr[i][j];
    }

    form_arr(h-2);
    int answer = 0;
    for(int i =0;i<w;i++){
        answer = max(answer, arr[0][i]);
    }
    cout << answer;
}
