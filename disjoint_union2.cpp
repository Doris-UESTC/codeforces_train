#include<iostream>
#include<vector>
using namespace std;
int parent[300005];
int sz[300005];
int mn[300005];
int mm[300005];
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
    sz[y_root]+=sz[x_root];
    mn[y_root]=min(mn[y_root],mn[x_root]);
    mm[y_root]=max(mm[y_root],mm[x_root]);
}
void get(int x){
    cout<<mn[x]<<" "<<mm[x]<<" "<<sz[x]<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
        mn[i]=i;
        mm[i]=i;
    }
    for(int i=0;i<m;i++){
        string op;
        int x,y;
        cin>>op;
        if(op=="union"){
            cin>>x>>y;
            uni(x,y);
        }else{
            cin>>x;
            get(find(x));
        }
    }
    return 0;
}