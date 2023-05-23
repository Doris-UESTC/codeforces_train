#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int dp[N][2];
vector<int> mp[N];
int n;
void dfs(int u,int fa){
    dp[u][0]=1;
    dp[u][1]=1;
    for(int i=0;i<mp[u].size();i++){
        int v=mp[u][i];
        if(v==fa) continue;
        dfs(v,u);
        dp[u][1]=dp[u][1]*dp[v][0];
        dp[u][0]*=(dp[v][1]+dp[v][0]);
        dp[u][0]%=1000000007;
        dp[u][1]%=1000000007;
    }
}
int32_t main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%1000000007<<endl;
}