#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int burst[n], waiting[n], tat[n];
    float avgWaiting = 0, avgTAT = 0;

    // Input burst times
    for(int i=0;i<n;i++){
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>burst[i];
    }

    // First process waiting time = 0
    waiting[0]=0;

    // Calculate waiting times
    for(int i=1;i<n;i++){
        waiting[i]=waiting[i-1]+burst[i-1];
    }

    // Calculate turnaround times
    for(int i=0;i<n;i++){
        tat[i]=waiting[i]+burst[i];

        avgWaiting += waiting[i];
        avgTAT += tat[i];
    }

    avgWaiting/=n;
    avgTAT/=n;

    // Output
    cout<<"\nProcess\tBurst\tWaiting\tTurnaround\n";

    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"
            <<burst[i]<<"\t"
            <<waiting[i]<<"\t"
            <<tat[i]<<endl;
    }

    cout<<"\nAverage Waiting Time = "<<avgWaiting<<endl;
    cout<<"Average Turnaround Time = "<<avgTAT<<endl;

    return 0;
}