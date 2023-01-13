#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int>> edges;
map<int,bool> visited;
int parent[1000005];
int main(){
    int n,m;
    cin>>n>>m;
    int l=INT_MAX,r=INT_MIN;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b]=c;
    }
}