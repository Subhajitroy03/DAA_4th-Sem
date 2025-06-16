#include<iostream>
#define max 100
using namespace std;
class Queue{
	public:
	int arr[max];
	int front;
	int rear;
	Queue(){
		front=rear=-1;
	}
	int isEmpty(){
		if(front==-1){
			return 1;
		}else{
			return 0;
		}
	}
	void enqueue(int element){
		if(isEmpty()){
			front++;
		}
		rear++;
		arr[rear]=element;
	}
	int dequeue(){
		if(isEmpty()){
			return -1;
		}
		int temp=arr[front];
		front++;
		if(front==rear+1){
			front=-1;
			rear=-1;
		}
		return temp;
	}
	void display(){
		if(isEmpty()){
			return;
		}
		for(int i=front;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
	}	
};

