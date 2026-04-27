#include<bits/stdc++.h>
using namespace std;
int main(){
    int page,capacity;
    cin>>page>>capacity;
    vector<int> pages(page);
    vector<int> frames;
    int fault=0;
    for(int i=0; i<page; i++){
        cin>>pages[i];
    }
    
    for(int i=0; i<page; i++){
        auto it= find(frames.begin(),frames.end(),pages[i]);
        if(it==frames.end()){  //page fault
            fault++;
            if(frames.size()==capacity){
                frames.erase(frames.begin());
            }

        }
        else{ //page hit
            frames.erase(it);
        }
        frames.push_back(pages[i]);
        for(int i=0; i<frames.size(); i++){
            cout<<frames[i]<<" ";
        }
        cout<<endl;
    }
    cout<<fault <<endl;

}