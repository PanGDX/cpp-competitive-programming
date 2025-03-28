#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
using namespace std;

typedef struct node{
	int row;
	int col;
	int direction;
} node;

typedef struct location{
	int row;
	int col;
} node;

char array[120][120];
queue<node>q;
set<location> traversed;



void starting(){
	//1 -> up, 2 -> right, 3 -> down, 4 -> left
	int start_row = 0, start_col = -1, direction = 2;
	
		
}

int main(){
	int row,col;
	cin >> row >> col;
	
	for(int i =0;i<row;i++){
		for(int j=0;j<col;j++){
			char t;
			scanf("%c", &t);
			if(t != ' ' && t!='\n') array[i][j]=t;
		}
	}
	
	
	
}
