#include<bits/stdc++.h>
using namespace std;
int l[200005],r[200005],p[400005],h[400005],parent[200005];
int find(int x){
    if(x!=parent[x]){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void uni(int x,int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root == y_root) return;
    parent[x_root] = y_root;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    for(int i=0;i<m;i++){
        cin>>p[i]>>h[i];
    }

}