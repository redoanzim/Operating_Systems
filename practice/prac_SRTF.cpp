#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of process: ";
    cin>>n;
    int bt[n],at[n],wt[n],rt[n],ct[n],tat[n];
    for(int i=0; i<n; i++){
        cin>>bt[i]>>at[i];
        rt[i]=bt[i];
    }
    int completed=0,time=0;
    while (completed<n)
    {
        int idx=-1;
        int temp=INT_MAX;
        for(int i=0; i<n; i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<temp){
                temp=rt[i];
                idx=i;
            }
        }
        if(idx==-1){
            time++;
        }
        else{
            rt[idx]--;
            time++;
            if(rt[idx]==0){
                completed++;
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
            }
        }
    }
    cout<<"PID\tBT\tAT\tWT\tTAT\tCT\n";

    for(int i=0;i<n;i++){
    cout<<i+1<<"\t"
        <<bt[i]<<"\t"
        <<at[i]<<"\t"
        <<wt[i]<<"\t"
        <<tat[i]<<"\t"
        <<ct[i]<<endl;
    }
    
}