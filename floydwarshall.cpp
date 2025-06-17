#include<iostream>
#define MAX 10
#define INF 100000
using namespace std;
int min(int a,int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}
void print(int arr[MAX][MAX],int n){
	for(int j=0;j<n;j++){
		cout<<j<<"-> ";
		for(int k=0;k<n;k++){
			cout<<arr[j][k]<<" ";
		}
		cout<<endl;
	}
}
void floyd_warshall(int matrix[MAX][MAX],int n){
	for(int i=0;i<n;i++){
		matrix[i][i]=0;
	}
	for(int k=0;k<n;k++){
		cout<<"With parent: "<<k<<endl;
		print(matrix,n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j && matrix[i][k]!=INF && matrix[k][j]!=INF){
					matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==INF){
				matrix[i][j]=-1;
			}
		}
	}
}
int main(void){
	int m,n;
	int adjmatrix[MAX][MAX];
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			adjmatrix[i][j]=INF;
		}
	}
	cout<<"Enter the no of vertices: ";
	cin>>n;
	cout<<"Enter the no of edges: ";
	cin>>m;
	int u,v,w;
	for(int i=0;i<m;i++){
		cout<<"Enter the edge(from to) and weight: ";
		cin>>u>>v>>w;
		adjmatrix[u][v]=w;
		
	}
	floyd_warshall(adjmatrix,n);
	
}
