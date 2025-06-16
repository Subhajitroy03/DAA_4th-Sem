#include<iostream>
#include "Queue.cpp"
using namespace std;

void dfs(int node,int adjmat[100][100],int va[],Queue& result,int v){
	va[node]=1;
	result.enqueue(node);
	for(int i=0;i<v;i++){
		if(adjmat[node][i]==1){
			if(!va[i]){
				dfs(i,adjmat,va,result,v);
			}
		}
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
	Queue result;
	int visited_array[v]={0};
	dfs(0,adjmat,visited_array,result,v);
	result.display();
	
}

