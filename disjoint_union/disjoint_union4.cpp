#include<bits/stdc++.h>
using namespace std;
int parent[200005];
vector<pair<string,pair<int,int>>> v;
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> ans;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
    }
    for(int i=0;i<k;i++){
        string op;
        int x,y;
        cin>>op>>x>>y;
        v.push_back(make_pair(op,make_pair(x,y)));
    }
    while(v.size()){
        string op = v.back().first;
        int x = v.back().second.first;
        int y = v.back().second.second;
        if(op=="ask"){
            if(find(x)==find(y)) 
            ans.push_back("YES");
            else 
            ans.push_back("NO");
        }else{
            uni(x,y);
        }
        v.pop_back();
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
}