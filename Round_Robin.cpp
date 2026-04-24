//PREEMPTIVE
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,tq;
    cin>>n;

    int at[n],bt[n],rt[n],wt[n],tat[n];

    for(int i=0;i<n;i++){
        cin>>at[i]>>bt[i];
        rt[i]=bt[i];
    }

    cin>>tq;

    int time=0,completed=0;
    float totalWT=0,totalTAT=0;

    while(completed<n){

        int idx=-1;

        for(int i=0;i<n;i++){

            if(at[i]<=time && rt[i]>0){
                idx=i;

                if(rt[i]>tq){
                    time+=tq;
                    rt[i]-=tq;
                }
                else{
                    time+=rt[i];
                    rt[i]=0;
                    completed++;

                    tat[i]=time-at[i];
                    wt[i]=tat[i]-bt[i];

                    totalWT+=wt[i];
                    totalTAT+=tat[i];
                }
            }
        }

        if(idx==-1)
            time++;
    }

    cout<<"\nP AT BT WT TAT\n";

    for(int i=0;i<n;i++)
        cout<<"P"<<i+1<<" "
            <<at[i]<<" "
            <<bt[i]<<" "
            <<wt[i]<<" "
            <<tat[i]<<endl;

    cout<<"\nAverage WT = "<<totalWT/n;
    cout<<"\nAverage TAT = "<<totalTAT/n;

    return 0;
}