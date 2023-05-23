#include<bits/stdc++.h>
using namespace std;
bool g[210][210];
bool st[210];
int rec[210];
int nv,ne;
bool check_clique(int cnt){
    for(int i=0;i<cnt;i++){
        for(int j=0;j<i;j++){
            if(!g[rec[i]][rec[j]])
            return false;
        }
    }
    return true;
}
bool check_max_clique(int cnt){
    memset(st,0,sizeof(st));
    for(int i=0;i<cnt;i++){
        st[rec[i]]=true;
    }
    for(int i=1;i<=nv;i++){
        if(!st[i]){
            bool flag=true;
            for(int j=0;j<cnt;j++){
                if(!g[i][rec[j]]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin>>nv>>ne;
    for(int i=0;i<ne;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;  
        g[v][u]=1;
    }
    int m;
    cin>>m;
    while(m--){
        int k;
        cin>>k;
        int cnt=0;
        for(int i=0;i<k;i++){
            cin>>rec[i];
        }
        if(check_clique(k)){
            if(check_max_clique(k)){
                cout<<"Yes"<<endl;
            }else{
                cout<<"Not Maximal"<<endl;
            }
        }else{
            cout<<"Not a Clique"<<endl;
        }
    }
    return 0;
}