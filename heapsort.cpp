#include<iostream>
using namespace std;
void heapify(int arr[],int size,int i){
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<=size && arr[largest]<arr[left]){
		largest=left;
	}
	if(right<=size && arr[largest]<arr[right]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,size,largest);
	}
}
void heapsort(int arr[],int size){
	for(int i=size/2;i>=1;i--){
		heapify(arr,size,i);
	}
	int t=size;
	while(t>1){
		swap(arr[t],arr[1]);
		t--;
		heapify(arr,t,1);
	}
}
int main(void){
	int arr[100];
	int n;
	cout<<"Enter no of elements: ";
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cout<<"Enter element: ";
		cin>>m;
		arr[i]=m;
	}
	heapsort(arr,n);
	for(int j=1;j<=n;j++){
		cout<<arr[j]<<" ";
	}
}
