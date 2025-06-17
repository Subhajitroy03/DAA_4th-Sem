#include<iostream>
using namespace std;
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<"Vertex "<<i<<"-> "<<"Color "<<arr[i]<<" ";
	}
	cout<<endl;
}
bool issafe(int node,int matrix[100][100],int n,int c,int color[]){
	for(int i=0;i<n;i++){
		if(matrix[node][i]==1 && color[i]==c){
			return false;
		}
	}
	return true;
}
void mcolor(int node,int matrix[100][100],int v,int m,int color[]){
	if(node==v){
		print(color,v);
		return;
	}
	for(int j=1;j<=m;j++){ //colour - > 1 to m 
		if(issafe(node,matrix,v,j,color)){
			color[node]=j;
			mcolor(node+1,matrix,v,m,color);
			color[node]=0; //for backtracking
		}
	}
}
int main(void){
	int m,n;
	int adjmatrix[100][100]={0};
	cout<<"Enter the no of vertices: ";
	cin>>n;
	cout<<"Enter the no of edges: ";
	cin>>m;
	int u,v;
	for(int i=0;i<m;i++){
		cout<<"Enter the edge: ";
		cin>>u>>v;
		adjmatrix[u][v]=1;
		adjmatrix[v][u]=1;
	}
	
	int c;
	cout<<"Enter no of colours: ";
	cin>>c;
	int color[n]={0};
	mcolor(0,adjmatrix,n,c,color);	
}
