#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of process: ";
    cin>> n;
    float avgWait=0,avgTat=0;
    int bt[n],wt[n],tat[n];
    for(int i=0; i<n; i++){
        cin>>bt[i];
    }
    wt[0]=0;
    for(int i=1; i<n; i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(int i=0; i<n; i++){
        tat[i]=wt[i]+bt[i];
    }
    for(int i=0; i<n; i++){
        avgWait+=wt[i];
        avgTat+=tat[i];
    }
    cout<< avgWait/n<<endl;
    cout<< avgTat/n <<endl;

}