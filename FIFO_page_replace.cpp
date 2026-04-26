#include <iostream>
using namespace std;

int main()
{
    int n, frames;

    cout<<"Enter number of pages: ";
    cin>>n;

    int pages[n];

    cout<<"Enter page reference string: ";
    for(int i=0;i<n;i++)
        cin>>pages[i];

    cout<<"Enter number of frames: ";
    cin>>frames;

    int frame[frames];

    // initially frames are empty
    for(int i=0;i<frames;i++)
        frame[i]=-1;

    int pageFault=0, pageHit=0;
    int index=0; // FIFO pointer

    for(int i=0;i<n;i++)
    {
        int found=0;

        // Check page hit
        for(int j=0;j<frames;j++)
        {
            if(frame[j]==pages[i])
            {
                found=1;
                pageHit++;
                break;
            }
        }

        // Page Fault
        if(found==0)
        {
            frame[index]=pages[i];
            index=(index+1)%frames; // circular FIFO
            pageFault++;
        }

        // Display frames
        cout<<"After "<<pages[i]<<" : ";
        for(int j=0;j<frames;j++)
            cout<<frame[j]<<" ";
        cout<<endl;
    }

    cout<<"\nTotal Page Faults = "<<pageFault<<endl;
    cout<<"Total Page Hits = "<<pageHit<<endl;

    return 0;
}