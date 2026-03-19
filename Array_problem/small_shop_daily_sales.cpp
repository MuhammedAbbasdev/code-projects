#include<iostream>
using namespace std;
int main(){
	int sales[7];
	int sum=0;
	float avg;
	
	for(int i=0; i<7; i++){
		cout<<"Enter the sales day "<<i+1<<" = ";
		cin>>sales[i];
		sum=sum+sales[i];
	}
	avg=sum/7.0;
	
	int HS=sales[0];
	int hd=0;
	for(int i=0; i<7; i++){
		if(HS<sales[i]){
			HS=sales[i];
			hd=i+1;
		}
	}
	
	int LS=sales[0];
	int ld=0;
	for(int i=0; i<7; i++){
		if(LS>sales[i]){
			LS=sales[i];
			ld=i+1;
		}
	}
	
	int count=0;
	for(int i=0; i<7; i++){
		if(sales[i]>avg){
			count++;
		}
	}
	cout<<endl;
	cout<<endl;
	cout<<"Total weekly sales = "<<sum<<endl;
	cout<<"Average sales = "<<avg<<endl;
	cout<<"Highest sales and the day occured = "<<HS<<" day "<<hd<<endl;
	cout<<"Lowest sales and the day occured = "<<LS<<" day "<<ld<<endl;
	cout<<"How many days sales were above average = "<<count<<endl;
}
