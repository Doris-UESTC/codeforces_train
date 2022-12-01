#include<bits/stdc++.h>
using namespace std;
int x[200005],y[200005],op[200005],color[200005]={-1},in[200005],out[200005],ans[200005];
vector<vector<int> > edge(200005);
vector<vector<int> > v(200005);
void dfs(int node){
    for(int x:edge[node]){
        if(color[x]==color[node]){
            cout<<"NO"<<endl;
            exit(0);
        }
        if(color[x]==-1){
            color[x]=color[node]^1;
            dfs(x);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>op[i]>>x[i]>>y[i];
        edge[x[i]].push_back(y[i]);
        edge[y[i]].push_back(x[i]);
    }
    for(int i=1;i<=n;i++){
        color[i]=0;
        dfs(i);
    }
    for(int i=0;i<m;i++){
        if(op[i]==1){
            v[x[i]].push_back(y[i]);
            in[y[i]]++;
        }else if(op[i]==2){
            v[y[i]].push_back(x[i]);
            in[x[i]]++;
        }
    }
    int now=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans[node]=++now;
        for(int x:v[node]){
            in[x]--;
            if(in[x]==0){
                q.push(x);
            }
        }
    }
    if(now!=n){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        cout<<(color[i]?"L":"R")<<ans[i]<<endl;
    }
    return 0;
}
