#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > edge(30005);
int vis[30005];
void dfs(int node){
    if(vis[node])
    return;
    vis[node]=1;
    for(int x:edge[node]){
        dfs(x);
    }
    cout<<node<<" ";
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    return 0;
}