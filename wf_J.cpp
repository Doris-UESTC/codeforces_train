#include<bits/stdc++.h>
using namespace std;
int m,n,q_time;
int main(){
    cin>>m>>n>>q_time;
    vector<vector<int> > adj(4*n+1);
    vector<int> belong(4*n+1,-1),deg(4*m+1);
    vector<char> o(n);
    vector<int> x(n),y(n),z(n);
    int cnt=1;
    for(int i=0;i<n;i++){
        cin>>o[i]>>x[i]>>y[i]>>z[i];
        x[i]--;
        y[i]--;
        z[i]--;
        if(o[i]=='S'){
            adj[x[i]].push_back(y[i]);
            adj[x[i]].push_back(z[i]);
            deg[y[i]]++;
            deg[z[i]]++;
            cnt+=2;
            belong[y[i]]=belong[z[i]]=i;
        }else{
            adj[x[i]].push_back(z[i]);
            adj[y[i]].push_back(z[i]);
            deg[z[i]]+=2;
            cnt++;
            belong[z[i]]=i;
        }
    }
    vector<int> len(cnt);
    len[0]=m;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u){
            int j=belong[u];
            if(o[j]=='S'){
                len[u]=(len[x[j]]+(u==y[j]))/2;
            }else{
                len[u]=len[x[j]]+len[y[j]];
            }
        }
        for(auto v:adj[u]){
            if(!--deg[v]){
                q.push(v);
            }
        }
    }
    function<int(int,int)> query=[&](int u,int k){
        if(k>=len[u]){
            return -1;
        }
        if(u==0){
            return k+1;
        }
        int j=belong[u];
        if(o[j]=='S'){
            return query(x[j],2*k+(u==z[j]));
        }else if(k<min(len[x[j]],len[y[j]])*2){
            if(k%2==0){
                return query(x[j],k/2);
            }else{
                return query(y[j],k/2);
            }
        }else if(len[x[j]]>len[y[j]]){
            return query(x[j],k-len[y[j]]);
        }else{
            return query(y[j],k-len[x[j]]);
        }
    };

    for(int i=0;i<q_time;i++){
        int x,k;
        cin>>x>>k;
        x--;
        k--;
        int ans=query(x,k);
        if(ans>0){
            cout<<ans<<endl;
        }else{
            cout<<"none"<<endl;
        }
    }
    return 0;
}