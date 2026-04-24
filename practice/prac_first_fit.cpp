#include<bits/stdc++.h>
using namespace std;
int main(){
    int BlockSize[]= {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int n= sizeof(processSize)/sizeof(processSize[0]);
    int m= sizeof(BlockSize)/sizeof(BlockSize[0]);
    int alloc[n];

    for(int i=0; i<n; i++){
        alloc[i]=-1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(BlockSize[j]>=processSize[i]){
                BlockSize[j]-=processSize[i];
                alloc[i]=j;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){

        cout<<"process "<<i+1<<"->";
        if(alloc[i]==-1)
        cout<<"Not allocated"<<endl;
        else{
            cout<<"Block "<<alloc[i]+1<<endl;
        }
    }

}
