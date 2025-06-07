#include<iostream>
#define INF 1000000
using namespace std;
void mat_mul(int d[],int n,int M[][10],int K[][10]){
	for(int i=0;i<n;i++){
		M[i][i]=0;
	}
	for(int diff=1;diff<n;diff++){
		for(int i=0;i+diff<n;i++){
			int j=i+diff;
			M[i][j]=INF;
			for(int k=i;k<j;k++){
				int q=M[i][k]+M[k+1][j]+d[i]*d[k+1]*d[j+1];
				if(q<M[i][j]){
					M[i][j]=q;
					K[i][j]=k;
				}
			}
			
			
		}
	}
}

int main(){
	int n;
	int d[10];
	cout<<"Enter the no of matrix: ";
	cin>>n;
	for(int m=0;m<n+1;m++){
		cout<<"Enter element: ";
		cin>>d[m];
	}
	int M[10][10]={0};
	int K[10][10]={0};
	mat_mul(d,n,M,K);
	cout<<"matrix M"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<M[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<"matrix K"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<K[i][j]<< "  ";
		}
		cout<<endl;
	}
	cout<<"Minimum no of multiplication required: "<<M[0][n-1]<<endl;	
}
