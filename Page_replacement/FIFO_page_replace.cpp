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

//Another shortcut Method

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int page,frame;
//     cin>>page>>frame;
//     vector<int> pages(page);
//     vector<int> frames;
//     int index=0;
//     int fault =0;
//     for(int i=0; i<page; i++){
//         cin>>pages[i];
//     }
//     for(int i=0; i<page; i++){
//         auto it=find(frames.begin(),frames.end(),pages[i]);
//         if(it==frames.end()){ //page fault
//             fault++;
//             if(frames.size()==frame){
//                 frames.erase(frames.begin());
//             }
//             frames.push_back(pages[i]);
//         }        
//     }

//     cout<<fault<<endl;
// }