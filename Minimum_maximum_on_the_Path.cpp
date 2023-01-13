#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d;
unordered_map<int,unordered_map<int,int>> edges;
unordered_map<int,bool> visited;
int parent[1000005];
bool judge(int num){
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1]=true;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        if(p.first==n){
            return true;
        }
        if(p.second==d){
            continue;
        }
        for(auto [k,v]:edges[p.first]){
                if(v>num||visited[k]){
                    continue;           
                }
                visited[k]=true;
                q.push({k,p.second+1});
                parent[k]=p.first;
        }
    }
    return false;
}
int32_t main(){
    cin>>n>>m>>d;
    int l=INT_MAX,r=INT_MIN;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b]=c;
        l=min(l,c);
        r=max(r,c);
    }
    int ans=-1;
    while(l<=r){
        visited.clear();
        int mid=l+(r-l)/2;
        if(judge(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    if(ans!=-1){
        vector<int> tmp;
        int x=n;
        while(x!=1){
            tmp.push_back(x);
            x=parent[x];
        }
        tmp.push_back(1);
        cout<<tmp.size()-1<<endl;
        for(int i=tmp.size()-1;i>=0;i--){
            cout<<tmp[i]<<" ";
        }
    }else{
        cout<<-1<<endl;
    }
}