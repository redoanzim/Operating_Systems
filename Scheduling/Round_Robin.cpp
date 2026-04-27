#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,tq;
    cin>>n;

    int at[n],bt[n],rt[n],wt[n],tat[n];

    for(int i=0;i<n;i++)
    {
        cin>>at[i]>>bt[i];
        rt[i]=bt[i];
    }

    cin>>tq;

    queue<int> q;
    bool inQueue[n]={false};

    int time=0,completed=0;
    float totalWT=0,totalTAT=0;

    // push processes that arrive at time 0
    for(int i=0;i<n;i++)
        if(at[i]==0)
            q.push(i), inQueue[i]=true;

    while(completed<n)
    {
        if(q.empty())
        {
            time++;
            for(int i=0;i<n;i++)
                if(at[i]<=time && rt[i]>0 && !inQueue[i])
                    q.push(i), inQueue[i]=true;
            continue;
        }

        int i=q.front();
        q.pop();

        // run process
        int run = min(tq, rt[i]);
        time += run;
        rt[i] -= run;

        // add newly arrived processes
        for(int j=0;j<n;j++)
            if(at[j]<=time && rt[j]>0 && !inQueue[j])
                q.push(j), inQueue[j]=true;

        // if still remaining, push back
        if(rt[i]>0)
            q.push(i);
        else
        {
            completed++;
            tat[i]=time-at[i];
            wt[i]=tat[i]-bt[i];

            totalWT+=wt[i];
            totalTAT+=tat[i];
        }
    }

    cout<<"\nP AT BT WT TAT\n";
    for(int i=0;i<n;i++)
        cout<<"P"<<i+1<<" "
            <<at[i]<<" "
            <<bt[i]<<" "
            <<wt[i]<<" "
            <<tat[i]<<endl;

    cout<<fixed<<setprecision(2);

    cout<<"\nAverage WT = "<<totalWT/n;
    cout<<"\nAverage TAT = "<<totalTAT/n;

    return 0;
}