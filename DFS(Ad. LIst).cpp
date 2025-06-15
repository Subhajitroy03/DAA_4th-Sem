#include<iostream>
#include "Queue.cpp"
using namespace std;
class Node{
	public:
		int vertex;
		Node* next;
		Node(int vertex){
			this->vertex=vertex;
			this->next=NULL;
		}
};
void addEnd(Node*& head,int vertex){
	Node* newNode=new Node(vertex);
	Node* temp=head;
	if(temp==NULL){
		head=newNode;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
}
void dfs(int node,Node* adjlist[],int va[],Queue& result,int v){
	va[node]=1;
	result.enqueue(node);
	if(adjlist[node]!=NULL){
			Node* temp=adjlist[node];
			while(temp!=NULL){
				if(!va[temp->vertex]){
					dfs(temp->vertex,adjlist,va,result,v);
				}
				temp=temp->next;
			}
		}
}
int main(void){
	int v,e;
	cout<<"Enter no of vertices: ";
	cin>>v;
	cout<<"Enter no of edges: ";
	cin>>e;
	Node* adjlist[v]={NULL};
	int m,n;
	for(int i=0;i<e;i++){
		cout<<"Enter edge: ";
		cin>>m>>n;
		addEnd(adjlist[m],n);
		addEnd(adjlist[n],m);
	}
	Queue result;
	int visited_array[v]={0};
	dfs(0,adjlist,visited_array,result,v);
	cout<<"DFS : "<<endl;
	result.display();
	
}

