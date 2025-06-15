#include<iostream>
#include "Queue.cpp"
using namespace std;
void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<< " ";
	}
}
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
void print_adjlist(Node* Adjlist[],int v){
	for(int i=0;i<v;i++){
		Node* temp=Adjlist[i];
		cout<<i <<" ->";
		while(temp!=NULL){
			cout<<temp->vertex<<" ";
			temp=temp->next;
		}
		cout<<endl;
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
	cout<<"Adjacency List: "<<endl;
	print_adjlist(adjlist,v);
	int bfs[100];
	int size=0;
	int visited_array[v]={0};
	Queue Q;
	visited_array[0]=1;
	Q.enqueue(0);
	while(!(Q.isEmpty())){
		int ele=Q.dequeue();
		bfs[size++]=ele;
		if(adjlist[ele]!=NULL){
			Node* temp=adjlist[ele];
			while(temp!=NULL){
				if(!visited_array[temp->vertex]){
					visited_array[temp->vertex]=1;
					Q.enqueue(temp->vertex);
				}
				temp=temp->next;
			}
		}
	}
	cout<<"BFS: "<<endl;
	printarray(bfs,size);
}
