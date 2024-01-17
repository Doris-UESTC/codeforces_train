#include<bits/stdc++.h>
using namespace std;
int parent[300005];
int find(int x){
    if(x!=parent[x]){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n+1;i++){
        parent[i]=i;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(find(x)==n+1){
            cout<<find(1)<<endl;
            parent[find(1)]=find(find(1)+1);
        }else{
            cout<<find(x)<<endl;
            parent[find(x)]=find(find(x)+1);
        }
    }
}