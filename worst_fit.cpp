#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> BlockSize = {100, 500, 200, 300, 600};
    vector<int> processSize = {212, 417, 112, 426};
    int m= BlockSize.size();
    int n=processSize.size();
    int alloc[n];
    for(int i=0; i<n; i++){
        alloc[i]=-1;
    }
    for(int i=0; i<n; i++){
        int worstidx=-1;
        for(int j=0; j<m; j++){
            if(BlockSize[j]>=processSize[i]){
                if(worstidx==-1 || BlockSize[j]>BlockSize[worstidx]){
                    worstidx=j;
                }

            }
        }
        if(worstidx!=-1){
            alloc[i]=worstidx;
            BlockSize[worstidx]-=processSize[i];

        }
    }
    for(int i=0; i<n; i++){
        cout<<"process "<<i+1<<" ->";
        if(alloc[i]!=-1){
            cout<<"Block "<<alloc[i]+1<<endl;
        }
        else{
            cout<<"Not allocated"<<endl;
        }
    }

}