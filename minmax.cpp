#include<iostream>
using namespace std;
class pair_minmax{
	public:
		int min;
		int max;
};
pair_minmax minmax(int arr[],int low,int high){
	pair_minmax result,left,right;
	if(low==high){
		result.max=arr[low];
		result.min=arr[low];
		return result;
	}
	if(low==high-1){
		if(arr[low]<arr[high]){
			result.min=arr[low];
			result.max=arr[high];
		}else{
			result.min=arr[high];
			result.max=arr[low];
		}
		return result;
	}
	int mid=(high+low)/2;
	left=minmax(arr,low,mid);
	right=minmax(arr,mid+1,high);
	if(left.min<right.min){
		result.min=left.min;
	}else{
		result.min=right.min;
	}
	
	if(left.max>right.max){
		result.max=left.max;
	}else{
		result.max=right.max;
	}
	return result;
}
int main(void){
	int arr[]={1,5,80,10,2,3,6,4};
	pair_minmax sol;
	sol=minmax(arr,0,7);
	cout<<"Min value: "<<sol.min<<endl;
	cout<<"Max value: "<<sol.max<<endl;
}
