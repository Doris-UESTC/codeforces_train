#include<bits/stdc++.h>
using namespace std;
int edge[5005][5005];
int minn[5005];
int u[5005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(edge[a][b]!=0){
            edge[a][b]=min(edge[a][b],c);
            edge[b][a]=min(edge[b][a],c);
        }
        else{
            edge[a][b]=c;
            edge[b][a]=c;
        }
    }
    memset(minn,0x7f,sizeof(minn));
    memset(u,1,sizeof(u));
    minn[1]=0;
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=1;j<=n;j++){
            if(u[j]&&(minn[j]<minn[k])){
                k=j;
            }
        }
        u[k]=0;
        for(int j=1;j<=n;j++){
            if(u[j]&&edge[k][j]!=0&&edge[k][j]<minn[j]){
                minn[j]=edge[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(u[i]){
            cout<<"orz"<<endl;
            return 0;
        }
    }
    int mmax=0;
    for(int i=1;i<=n;i++){
        mmax+=minn[i];
    }
    cout<<mmax<<endl;
    return 0;
}