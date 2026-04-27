#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter number of process: ";
    cin >> n;
    int pri[n];
    int bt[n], wt[n], ct[n], tat[n], at[n], rt[n];

    for (int i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i] >> pri[i];
        rt[i]=bt[i];
    }

    int complete = 0, time = 0;
    while (complete < n)
    {   
        int idx=-1;
        int temp=INT_MAX;
       for(int i=0; i<n; i++){
            if(at[i]<=time && rt[i]>0){
                if(pri[i]<temp){
                    temp=pri[i];
                    idx=i;
                }
            } 
        }

        if(idx==-1){
            time++;
        }
        else{
            rt[idx]--;
            time++;
            if(rt[idx]==0){
                complete++;
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
            }
        }

    }
    cout << "PID\tBT\tAT\tWT\tTAT\tCT\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"
             << bt[i] << "\t"
             << at[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << "\t"
             << ct[i] << endl;
    }
}