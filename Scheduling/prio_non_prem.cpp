//Priority Algorithm non preemptive version

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of process: ";
    cin>>n;
    int at[n],bt[n],p[n],wt[n],ct[n],tat[n],rt[n];
    int completed =0,time=0;
    for(int i=0; i<n; i++){
        cin>>at[i]>>bt[i]>>p[i];
    }

    while (completed<n)
    {   
        int hp=INT_MAX;
        int idx=-1;
        for(int i=0; i<n; i++){
            if(at[i]<=time && rt[i]>0 && p[i]<hp){
                hp=p[i];
                idx=i;
            }
        }
        if(idx==-1){
            time++;
        }
        else{
            time+=bt[idx];
            completed++;
            rt[idx]=0;
          
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
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
    
    return 0;
}