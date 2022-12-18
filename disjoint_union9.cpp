#include<bits/stdc++.h>
using namespace std;
int p[300005];
int depth[300005];
int find(int x){
    if(x!=p[x]){
        p[x]=find(p[x]);
    }
    return p[x];
}
void uni(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    p[x]=y;
    depth[x]=depth[y]+1;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
        depth[i]=0;
    }   
    for(int i=1;i<=m;i++){
        int op,x,y;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            uni(x,y);
            for(int j=1;j<=n;j++){
                cout<<depth[j]<<" ";
            }
            cout<<""<<endl;
        }else{
            cin>>x;
            cout<<depth[x]<<endl;
        }
    }
}