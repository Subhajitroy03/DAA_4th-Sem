#include<iostream>
using namespace std;
void printboard(char board[][10],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool isSafe(char board[][10],int n,int row,int col){
	for(int k=0;k<row;k++){
		if(board[k][col]=='Q'){
			return false;
		}
	}
	
	for(int k=0;k<col;k++){
		if(board[row][k]=='Q'){
			return false;
		}
	}
	int k=row-1;
	int m=col-1;
	for(;k>=0 && m>=0;k--,m--){
		if(board[k][m]=='Q'){
			return false;
		}
	}
	int k1=row-1;
	int m1=col+1;
	for(;k1>=0 && m1<n;k1--,m1++){
		if(board[k1][m1]=='Q'){
			return false;
		}
	}
	return true;		
}
void placeQueens(char board[][10],int row,int n){
	if(row==n){
		cout<<" Solution: "<<endl;
		printboard(board,n);
		return;
	}
	for(int j=0;j<n;j++){
		if(isSafe(board,n,row,j)){
			board[row][j]='Q';
			placeQueens(board,row+1,n);
			board[row][j]='.';
		}
	}
}
int main(){
	int n;
	cout<<"Enter the no of queens: (less than 10): ";
	cin>>n;
	char board[n][10];
	for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++) {
        	board[i][j] = '.';
    }
}
	placeQueens(board,0,n);
}
