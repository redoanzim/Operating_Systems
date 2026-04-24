//NON PREEMPTIVE
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int burst[n], waiting[n];
    float avgWaiting = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst[i];
    }

    // Waiting time for first process
    waiting[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    // Calculate average waiting time
    for (int i = 0; i < n; i++) {
        avgWaiting = avgWaiting + waiting[i];
    }

    avgWaiting = avgWaiting / (float)n;   // ✅ force decimal output

    // Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << burst[i] << "\t\t"
             << waiting[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << avgWaiting << endl;

    return 0;
}
