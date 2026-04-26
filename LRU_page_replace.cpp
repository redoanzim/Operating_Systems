#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, capacity, faults = 0;

    cout << "Enter number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> capacity;

    vector<int> frames;

    for (int page : pages) {
        // Find if page exists in frames
        auto it = find(frames.begin(), frames.end(), page);

        if (it == frames.end()) { // Page Fault
            faults++;
            if (frames.size() == capacity) {
                frames.erase(frames.begin()); // Remove Least Recently Used (front)
            }
        } else { // Page Hit
            frames.erase(it); // Remove it from its current position
        }
        
        frames.push_back(page); // Add to the end (Most Recently Used)

        // Display
        cout << "After " << page << " : ";
        for (int f : frames) cout << f << " ";
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << faults << endl;
    return 0;
}