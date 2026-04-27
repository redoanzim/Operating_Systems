#include<bits/stdc++.h>
using namespace std;
int main(){
    int page,frame;
    cin>>page>>frame;
    vector<int> pages(page);
    vector<int> frames;
    int index=0;
    int fault =0;
    for(int i=0; i<page; i++){
        cin>>pages[i];
    }
    for(int i=0; i<page; i++){
        auto it=find(frames.begin(),frames.end(),pages[i]);
        if(it==frames.end()){ //page fault
            fault++;
            if(frames.size()==frame){
                frames.erase(frames.begin());
            }
            frames.push_back(pages[i]);
        }        
    }

    cout<<fault<<endl;
}