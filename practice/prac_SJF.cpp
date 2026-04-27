#include<bits/stdc++.h>
using namespace std;

int main(){

int n;
cout<<"Enter number of process: ";
cin>>n;

int pid[n],bt[n],org[n],wt[n],ct[n],tat[n],at[n];

int complete=0,time=0;

for(int i=0;i<n;i++){
    cin>>pid[i]>>bt[i]>>at[i];
    org[i]=bt[i];
}

while(complete<n){

    int idx=-1;
    int temp=INT_MAX;

    for(int i=0;i<n;i++){
        if(at[i]<=time && bt[i]<temp){
            temp=bt[i];
            idx=i;
        }
    }

    if(idx!=-1){

        int burst=bt[idx];

        time+=burst;
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-burst;

        bt[idx]=INT_MAX;
        complete++;
    }
    else{
        time++;
    }
}

cout<<"PID\tBT\tAT\tWT\tTAT\tCT\n";

for(int i=0;i<n;i++){
cout<<pid[i]<<"\t"
    <<org[i]<<"\t"
    <<at[i]<<"\t"
    <<wt[i]<<"\t"
    <<tat[i]<<"\t"
    <<ct[i]<<endl;
}

}