#include<iostream>
using namespace std;

class object{
	public:
		char objname;
		int profit;
		int weight;
		float pwratio;
		
		object(char objname,int profit,int weight){
			this->objname=objname;
			this->profit=profit;
			this->weight=weight;
			this->pwratio=(float)profit/weight;
		}
};
void sort(object* arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]->pwratio<arr[j]->pwratio){
				object* temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	object* arr[10];
	int n,m;
	cout<<"Enter the no of objects: ";
	cin>>n;
	cout<<"Enter the total capacity: ";
	cin>>m;
	for(int i=0;i<n;i++){
		char on;
		int p;
		int w;
		cout<<"Enter the object name: ";
		cin>>on;
		cout<<"Enter the profit: ";
		cin>>p;
		cout<<"Enter the weight: ";
		cin>>w;
		arr[i]=new object(on,p,w);
		
	}
	sort(arr,n);
	float profit=0;
	int i;
	for(i=0;i<n;i++){
		if(m>=arr[i]->weight and m>0){
			profit=profit+arr[i]->profit;
			m=m-arr[i]->weight;
			cout<<"Object: "<<arr[i]->objname<<"x: 1"<<endl;
		}else{
			break;
		}
	}
	if(m>0){
		profit=profit+(arr[i]->profit)*((float)m/arr[i]->weight);
		cout<<"Object: "<<arr[i]->objname<<" x: "<<(float)m/arr[i]->weight<<endl;
	}
	cout<<"Total profit: "<<profit<<endl;
}
