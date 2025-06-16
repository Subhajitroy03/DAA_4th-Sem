#include<iostream>
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
	print_adjlist(adjlist,v);
}
