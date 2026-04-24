//PREEPMTIVE VERSION
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], rt[n], wt[n], tat[n];

    for(int i=0;i<n;i++){
        cin >> at[i] >> bt[i];
        rt[i]=bt[i];
    }

    int time=0, completed=0;
    float totalWT=0,totalTAT=0;

    while(completed<n){
        int idx=-1, minRT=1e9;

        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<minRT){
                minRT=rt[i];
                idx=i;
            }
        }

        if(idx==-1){
            time++;   // CPU idle
        }
        else{
            rt[idx]--;
            time++;

            if(rt[idx]==0){
                completed++;

                tat[idx]=time-at[idx];
                wt[idx]=tat[idx]-bt[idx];

                totalWT+=wt[idx];
                totalTAT+=tat[idx];
            }
        }
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