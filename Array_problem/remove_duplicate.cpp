#include<iostream>
using namespace std;
int main(){
    int x[5]={1,1,2,2,10};
    for(int i=0; i<5; i++){
    	
    	bool duplicate=false;   //means fasle=0
    	
    	for(int j=4; j>i; j--){
    		
    		if(x[i]==x[j]){
    			duplicate=true;   // means true=1
    			break;
			}
		}
		if(!duplicate){
			cout<<x[i]<<" ";
		}
	}
}
