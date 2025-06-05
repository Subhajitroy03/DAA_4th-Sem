#include<iostream>
using namespace std;

class job{
	public:
		char jobname;
		int profit;
		int deadline;
		
		job(char jobname,int profit,int deadline){
			this->jobname=jobname;
			this->profit=profit;
			this->deadline=deadline;
		}
};
int max_deadline(job* arr[],int n){
	int max=arr[0]->deadline;
	for(int i=1;i<n;i++){
		if(arr[i]->deadline>max){
			max=arr[i]->deadline;
		}
	}
	return max;
}
void sort(job* arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]->profit<arr[j]->profit){
				job* temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	job* arr[10];
	int n;
	cout<<"Enter the no of jobs: ";
	cin>>n;
	for(int i=0;i<n;i++){
		char jn;
		int p;
		int d;
		cout<<"Enter the job name: ";
		cin>>jn;
		cout<<"Enter the profit: ";
		cin>>p;
		cout<<"Enter the deadline: ";
		cin>>d;
		arr[i]=new job(jn,p,d);
		
	}
	sort(arr,n);
	float profit=0;
	int maximum=max_deadline(arr,n);
	char sol[maximum];
	for(int i=0;i<maximum;i++){
		sol[i]='#';
	}
	for(int i=0;i<n;i++){
		int d=arr[i]->deadline;
		if(sol[d-1]=='#'){
			sol[d-1]=arr[i]->jobname;
			profit=profit+arr[i]->profit;
		}else{
			int j=d-1;
			while(j>=0){
				if(sol[j]=='#'){
					sol[j-1]=arr[i]->jobname;
					profit=profit+arr[i]->profit;
					break;
				}
				else{
					j--;
				}
			}
		}
	}
	for(int k=0;k<maximum;k++){
		if(sol[k]=='#'){
			cout<<k+1<<" - No job assigned"<<endl;
		}else{
			cout<<k+1<<"- job no: "<<sol[k]<<endl;
		}
	}
	cout<<"Total profit: "<<profit<<endl;
}
