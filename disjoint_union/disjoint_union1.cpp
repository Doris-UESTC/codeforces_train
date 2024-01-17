#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
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
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        string op;
        int x,y;
        cin>>op>>x>>y;
        if(op=="union"){
            uni(x,y);
        }else{
            if(find(x)==find(y)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}