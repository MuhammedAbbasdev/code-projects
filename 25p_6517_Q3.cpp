#include<iostream>
using namespace std;

int main(){

    // -------- National Multi-Region Disaster Intelligence System --------

    int type, sev, resp, people;
    int incidents;

    int national_total = 0;

    int highest = 0, lowest = 9999999;
    int high_region = 0, low_region = 0;
    
    cout<<"-------------------- National Multi-Region Disaster Intelligence System -----------------"<<endl<<endl;

    for(int region=1; region<=3; region++){

        int region_total = 0;
        int prev_sev1 = -1, prev_sev2 = -1;

        cout<<"-------- Region "<<region<<" --------"<<endl;

        for(int day=1; day<=4; day++){

            int day_sev_count = 0;

            cout<<"Day "<<day<<endl<<"incidents: ";
            cin>>incidents;

            for(int i=1; i<=incidents; i++){
 
                cout<<"Enter Type: ";
                cin>>type;
                cout<<"Enter Severity: ";
                cin>>sev;
                cout<<"Enter ResponseTime: ";
                cin>>resp;
                cout<<"Enter AffectedPeople: ";
                cin>>people;

                int score = 0;

                // ----- Base Score -----
                switch(type){
                    case 1: 
					  score = sev * 100; 
					  break;
                    case 2: 
					  score = sev * 150; 
					  break;
                    case 3: 
					  score = sev * 300; 
					  break;
                    case 4: 
					  score = sev * 200; 
					  break;
                }

                // ----- Severity + Response Penalty -----
                if(sev >= 8 && resp > 45){
                    score += 700;
                }

                // ----- Affected People Bonus -----
                if(people > 2000){
                    score += score * 0.25;
                }

                // ----- Severity >=7 Counter -----
                if(sev >= 7){
                    day_sev_count++;
                }

                // ----- Escalation Bonus (3 increasing severity) -----
                if(prev_sev1 != -1 && prev_sev2 != -1){
                    if(prev_sev2 < prev_sev1 && prev_sev1 < sev){
                        score += 1000;
                    }
                }

                prev_sev2 = prev_sev1;
                prev_sev1 = sev;

                region_total += score;
            }

            // ----- 3 or More High Severity Same Day -----
            if(day_sev_count >= 3){
                region_total += 1500;
            }
            cout<<endl;
        }

        // ----- Region Status -----
        cout<<"Region "<<region<<" Total Score: "<<region_total<<" ";

        if(region_total > 40000){
            cout<<"(Critical)";
        }
        else if(region_total < 10000){
            cout<<"(Stable)";
        }
        else{
            cout<<"(Normal)";
        }

        cout<<endl;

        // ----- Highest & Lowest Tracking -----
        if(region_total > highest){
            highest = region_total;
            high_region = region;
        }

        if(region_total < lowest){
            lowest = region_total;
            low_region = region;
        }

        national_total += region_total;
        cout<<endl;
    }

    // ----- Final Outputs -----
    cout<<"Highest Impact Region: Region "<<high_region<<endl;
    cout<<"Lowest Impact Region: Region "<<low_region<<endl;
    cout<<"National Total Score: "<<national_total<<endl;

    if(national_total > 100000){
        cout<<"National Emergency Declared";
    }
    else{
        cout<<"No National Emergency";
    }

    return 0;
}

