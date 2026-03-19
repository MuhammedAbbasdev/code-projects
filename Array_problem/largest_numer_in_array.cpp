#include<iostream>
using namespace std;
int main(){
//	int x[5];
//	cin>>x[0];
//	cin>>x[1];
//	cin>>x[2];
//	cin>>x[3];
//	cin>>x[4];
//	
//	int max=x[0];
//	int n=sizeof(x) / sizeof(x[0]);
//	
//	for(int i=1; i<n; i++){
//		
//		if(x[i]>max){
//			
//			max=x[i];
//		}
//		
//	}
//	cout<<"largest number is :"<<max<<endl;

   int y[]={2,4,6,8};
   int min=y[0];
   int n=sizeof(y) / sizeof(y[0]);
   for(int i=1; i<n; i++){
   	
   	if(y[i]<min){
   		min=y[i];
	   }
   }
   cout<<"minimum number of:"<<min<<endl;






	
}
