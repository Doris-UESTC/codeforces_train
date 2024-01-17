#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[200005];
int find(int x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void uni(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
struct Node {
    int x,y,v;
    bool operator < (const Node &b) const{
        return v<b.v;
    }
}node[200005];
int32_t main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>node[i].x>>node[i].y>>node[i].v;
    }
    sort(node+1,node+m+1);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int res=0;
    int k=0;
    for(int i=1;i<=m;i++){
        if(find(node[i].x)!=find(node[i].y)){
            uni(node[i].x,node[i].y);
            res+=node[i].v;
            k++;
        }
        if(k==n-1)
        break;
    }
    cout<<res<<endl;
}