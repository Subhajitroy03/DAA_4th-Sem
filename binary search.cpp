#include<iostream>
using namespace std;
int binary_search(int arr[],int l,int r,int target){
	if(l<r){
		int mid=(l+r)/2;
		if(arr[mid]==target){
			return mid;
		}
		if(arr[mid]>target){
			return binary_search(arr,l,mid-1,target);
		}
		if(arr[mid]<target){
			return binary_search(arr,mid+1,r,target);
		}
	}
}
int main(void){
	int arr[]={5,6,7,8,9,10,23,58};
	cout<<binary_search(arr,0,7,9);
}
