#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Number of process : ";
    cin>>n;
    int at[n],bt[n],ct[n],p[n],wt[n],tat[n],rt[n];
    for(int i=0; i<n; i++){
        cout<<"Enter arrival time for process"<<i+1<<": ";
        cin>>at[i];
        cout<<"Enter burst time for process"<<i+1<<": ";
        cin>>bt[i];
        cout<<"Enter priority for process"<<i+1<<": ";
        cin>>p[i];
        rt[i] =bt[i];
    }
    int completed=0,time=0;
    
    while(completed<n){
        int idx=-1;
        int high =INT_MIN;
        for(int i=0; i<n; i++){
            if(at[i]<=time && rt[i]>0){
                if(p[i]>high){
                    high=p[i];
                    idx=i;
                }
            }
        }
        if(idx!=-1){
            time++;
            rt[idx]--;
            if(rt[idx]==0){
                completed++;
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
            } 
        }
        else{
            time++;
        }
    }
    // Calculate averages
    float total_wt = 0, total_tat = 0;

    printf("\nID\tAT\tBT\tP\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], p[i],
               ct[i], tat[i], wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}