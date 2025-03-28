#include <iostream>
#include  <bits/stdc++.h> 
#include  <string>

using namespace std; 

int process(string matrix[], int row_count, int col_count){
	return 0;	
}

string *transpose(string *matrix[], int row,int col){
	string copy_matrix[100];
	for(int i =0;i<col;i++){
		for(int j=0;j<row;j++){
			copy_matrix[i][j] = matrix[j][i];
		}
	}
	free(matrix);
	return copy_matrix;
}


int main(){
	string temp;
	string matrix[100];
	int row,col;
	
	int total = 0;
	while(1){
		getline(cin, temp);
		if(temp=="stop") break;
		else if(temp.empty()){
			printf("ROW: %d COL: %d\n", row,col);
			total += process(matrix, row, col);
			// transpose 
			transpose(&matrix, row, col);
			
			total += process(matrix, row, col);
			row = 0;
			col = 0;
		}
		else{
			col = temp.length();
			matrix[row] = temp;
			row++;
		}
	}
	printf("%d", total);
}
