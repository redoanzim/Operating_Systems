//NON PREEMPTIVE
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];
    bool done[n] = {false};

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter AT and BT for P" << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    int completed = 0, currentTime = 0;

    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        // find shortest job
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= currentTime && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            currentTime++; // idle
        } else {
            currentTime += bt[idx];
            ct[idx] = currentTime;   // ✔️ store completion time
            done[idx] = true;
            completed++;
        }
    }

    float totalWT = 0, totalTAT = 0;

    // calculate WT and TAT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nP\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "\nAverage WT = " << totalWT / n;
    cout << "\nAverage TAT = " << totalTAT / n << endl;

    return 0;
}