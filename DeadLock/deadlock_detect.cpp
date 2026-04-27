#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], request[n][m], avail[m];

    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Request Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> request[i][j];

    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < m; i++)
        cin >> avail[i];

    bool finish[n] = {false};
    int work[m];

    for(int i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {

                bool canRun = true;

                for(int j = 0; j < m; j++) {
                    if(request[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }

                if(canRun) {
                    for(int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if(!found)
            break; // deadlock detected
    }

    cout << "\nDeadlocked Processes: ";

    bool deadlock = false;

    for(int i = 0; i < n; i++) {
        if(!finish[i]) {
            cout << "P" << i << " ";
            deadlock = true;
        }
    }

    if(!deadlock)
        cout << "None (No Deadlock)";

    cout << endl;

    return 0;
}