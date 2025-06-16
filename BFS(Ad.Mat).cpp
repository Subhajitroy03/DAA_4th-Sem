#include<iostream>
#include "Queue.cpp"
using namespace std;
void printmatrix(int arr[100][100],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<< " ";
		}
		cout<<endl;
	}
}
void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<< " ";
	}
}
int main(void){
	int v,e;
	cout<<"Enter no of vertices: ";
	cin>>v;
	cout<<"Enter no of edges: ";
	cin>>e;
	int adjmat[100][100]={0};
	int m,n;
	for(int i=0;i<e;i++){
		cout<<"Enter edge: ";
		cin>>m>>n;
		adjmat[m][n]=1;
		adjmat[n][m]=1;
	}
	int bfs[100];
	int size=0;
	int visited_array[v]={0};
	Queue Q;
	visited_array[0]=1;
	Q.enqueue(0);
	while(!(Q.isEmpty())){
		int ele=Q.dequeue();
		bfs[size++]=ele;
		for(int i=0;i<v;i++){
			if(adjmat[ele][i]==1){
				if(!visited_array[i]){
					visited_array[i]=1;
					Q.enqueue(i);
				}
			}
		}
	}
	printarray(bfs,size);
}

