#include<bits/stdc++.h>
using namespace std;
int parent[200005];
int extra[200005];
int tmp_score[200005];
int _size[200005];
int find(int x){
    // if(x!=parent[x]){
    //     parent[x]=find(parent[x]);
    // }
    // return parent[x];
    return (x== parent[x] ? x : find(parent[x]));
}
void uni(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_size[x]<_size[y]){
        swap(x,y);
    }
    _size[x]+=_size[y];
    parent[y]=x;
    extra[y]=tmp_score[x];
}
int score(int x){
    return x==parent[x]?tmp_score[x]:(tmp_score[x]+score(parent[x])-extra[x]);
}
void add_score(int x,int y){
    tmp_score[find(x)]+=y;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        tmp_score[i]=0;
        _size[i]=1;
    }
    for(int i=0;i<m;i++){
        string op;
        int x,y;
        cin>>op;
        if(op=="join"){
            cin>>x>>y;
            uni(x,y);
        }else if(op=="add"){
            cin>>x>>y;
            add_score(x,y);
        }else if(op=="get"){
            cin>>x;
            cout<<score(x)<<endl;
        }
    }
    return 0;
}