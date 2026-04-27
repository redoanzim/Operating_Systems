#include <iostream>
using namespace std;

int main() {
    int n, m; // n = processes, m = resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Max Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < m; i++)
        cin >> avail[i];

    // Calculate Need Matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finished[n] = {false};
    int safeSeq[n];
    int count = 0;
    while(count<n){
        bool found=false;
        for(int i=0; i<n; i++){
            bool cr=true;
            for(int j=0; j<m; j++){
                if(need[i][j]>avail[j]){
                    cr=false;
                    break;
                }
            }
        }

        if(!found){
            cout<<"NO safe SEquence"<<endl;
            return 0;
        }
    }

}