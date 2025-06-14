#include<iostream>
#include<limits>
using namespace std;
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}
void merge(int arr[],int p,int q,int r){
	int n=q-p+1;
	int m=r-q;
	int left[n+1];
	int right[m+1];
	int i,j;
	for(i=0;i<n;i++){
		left[i]=arr[p+i];
	}
	for(j=0;j<m;j++){
		right[j]=arr[q+1+j];
	}
	left[n]=INT_MAX;
	right[m]=INT_MAX;
	i=0;
	j=0;
	int k=0;
	for(k=0;k<=r-p;k++){
		if(left[i]<right[j]){
			arr[p+k]=left[i];
			i++;
		}else{
			arr[p+k]=right[j];
			j++;
		}
	}
	cout << "After merging from index " << p << " to " << r << ": ";
	print(arr, r-p+1);
}
void mergesort(int arr[],int p,int r){
	if(p<r){
		int mid=(p+r)/2;
		mergesort(arr,p,mid);
		mergesort(arr,mid+1,r);
		merge(arr, p, mid, r);
	}
}
int main(void){
	int arr[]={1,5,6,9,3};
	mergesort(arr,0,4);
	cout<<"The sorted array: "<<endl;
	print(arr,5);
}
