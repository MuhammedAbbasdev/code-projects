#include<iostream>
using namespace std;
int main(){
	int x[5];
	for(int i=0; i<5; i++){
		cin>>x[i];
	}
	cout<<"remove one idex  "<<endl;
	for(int i=0; i<5; i++){
	
	if(x[i]==4){
		continue;
	}
	cout<<x[i]<<" ";
	}
}
