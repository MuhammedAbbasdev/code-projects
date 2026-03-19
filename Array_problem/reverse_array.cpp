#include<iostream>
using namespace std;
int main(){
	int x[]={1,2,3,4,5};
	int n=sizeof(x) / sizeof(x[0]);
	for(int i=4; i<=n; i--){
		
		cout<<x[i]<<"";
//		if(i==0){
//			break;
//		}
	}
	
}
