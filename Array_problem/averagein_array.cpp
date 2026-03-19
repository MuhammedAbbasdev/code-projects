#include<iostream>
using namespace std;
int main(){
	int x[]={2,3,6,8,10};
	int n=sizeof(x) / sizeof(x[0]);
	int sum=0;
	
	for(int i=0; i<n; i++){
		sum=sum+x[i];
	}
	double avg=sum/n;
	cout<<"average of element :"<<avg<<endl;
}
