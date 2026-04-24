#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter Number of process: " << endl;
    cin >> n;
    cout << "Enter Number of resources: " << endl;
    cin >> m;
    int all[n][m], max[n][m], need[n][m];
    int avail[m];
    cout << "Allocate process: " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> all[i][j];
        }
    }

    cout << "Max need " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> max[i][j];
        }
    }
    cout << "Enter available resources: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }
    // calculate need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
    int count = 0;
    bool finished[n] = {false};
    int safeSeq[n];
    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++){
            if (!finished[i]){
                bool canRun = false;
                for (int j = 0; j < m; j++){
                    if (need[i][j] > avail[j]){
                        break;
                    }
                    canRun = true;
                }
                if (canRun){
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += all[i][j];
                    }
                     finished[i]=true;
                     safeSeq[count++]=i;
                     found =true;
                }
            } 
        }
        if (found == false){
                cout << "No safe sequence" << endl;
                return 0;
            }
    }
    cout<<"Safe State"<<endl;
    for(int i=0; i<n; i++){
        cout<<safeSeq[i]<<" " <<endl;
    }
}