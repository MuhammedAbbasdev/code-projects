#include<iostream>
using namespace std;
int main(){

    //  ------------------Advanced Banking Fraud Risk Engine----------

    int tran, num, cat;
    int bal = 500000;
    int risk = 0;

    int consec_withd = 0;
    int consec_itran = 0;

    cout<<"------------------Advanced Banking Fraud Risk Engine----------"<<endl<<endl;

    for(int day=1; day<=5; day++){

        int daily_total = 0;
        int withd_today = 0;   
        int itran_today = 0;   

        cout<<"--------Day "<<day<<" ---------"<<endl;
        cout<<"Enter number of transactions: ";
        cin>>num;

        for(int n=1; n<=num; n++){

            cout<<endl<<"1 - Deposit "<<endl
                <<"2 - Withdrawal"<<endl
                <<"3 - International Transfer"<<endl;

            cout<<"Transaction Type : ";
            cin>>cat;

            cout<<"Enter transaction amount: ";
            cin>>tran;

            daily_total += tran;

            switch(cat){

                case 1: // Deposit
                    bal += tran;

                    // Deposit after two withdrawals
                    if(consec_withd >= 2){
                        risk -= 20;
                        if(risk < 0)
                            risk = 0;
                    }

                    consec_withd = 0;
                    consec_itran = 0;
                    break;

                case 2: // Withdrawal
                    withd_today=1;

                    if(tran > bal * 0.5){
                        risk += 30;
                    }

                    bal -= tran;

                    consec_withd++;
                    consec_itran = 0;

                    if(consec_withd==3){
                        risk += 40;
                    }

                    break;

                case 3: // International Transfer
                    itran_today = 1;

                    bal -= tran;

                    consec_itran++;
                    consec_withd = 0;

                    if(consec_itran==2){
                        risk += 25;
                    }

                    break;
            }

            // Negative balance rule
            if(bal<0){
                risk += 100;
            }

            cout<<endl;
        }

        // Daily total exceeding 300000
        if(daily_total>300000){
            risk += 50;
        }

        // Withdrawal + International same day rule
        if(withd_today==1 && itran_today==1 && daily_total>200000){
            risk += 60;
        }
    }

    cout<<endl<<"Final Balance: "<<bal<<endl;
    cout<<"Total Risk Score: "<<risk<<endl;

    if(risk <= 50){
        cout<<"Account Status: Safe";
    }
    else if(risk <= 120){
        cout<<"Account Status: Medium Risk";
    }
    else{
        cout<<"Account Status: High Risk";
    }

    return 0;
}
