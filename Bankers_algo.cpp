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

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finished[i]) {
                bool canRun = true;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                if(canRun) {
                    for(int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }

        if(!found) {
            cout << "\nSystem is NOT in safe state!\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state.\nSafe sequence: ";
    for(int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] << " ";

    cout << endl;
    return 0;
}