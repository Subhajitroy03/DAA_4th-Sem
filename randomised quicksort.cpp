#include<iostream>
#include<cstdlib> 
using namespace std;
void swap(int arr[],int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}
int partition(int arr[],int l,int r){
	int num = l + rand() % (r - l + 1);
	swap(arr,l,num);
	int p=arr[l];
	int i=l;
	for(int j=l+1;j<=r;j++){
		if(arr[j]<=p){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i,l);
	cout << "After partitioning with pivot " << p << ": ";
	for(int k = l; k <= r; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
	return i;
	
}
void rquicksort(int arr[],int p,int q){
	if(p<q){
		int x=partition(arr,p,q);
		rquicksort(arr,p,x);
		rquicksort(arr,x+1,q);
	}
}
int main(void){
	int arr[]={5,1,3,9,6,2};
	cout<<"Initial Array: ";
	print(arr,6);
	rquicksort(arr,0,5);
	
	cout<<"Final Array: ";
	print(arr,6);
}
