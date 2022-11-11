/* https://codeforces.com/contest/152/problem/E */
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,y;
};
int cost[205][205];
int dp[205][1<<7];
int pre[205][1<<7];
bool visited[205][1<<7];
char g[205][205];
int n,m,k;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int _hash[205];
queue<Node> q;
bool check(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m){
        return true;
    }
    return false;
}
void dfs(int pos,int state){
    int x=pos/m;
    int y=pos%m;
    g[x][y]='X';
    if(pre[pos][state]==-1)
    return;
    int to=pre[pos][state]/1000;
    int new_state=pre[pos][state]%1000;
    dfs(to,new_state);
    if(new_state-state){
        dfs(to,state-new_state);
    }
}
void modify(int num,int state,int w,int fa){
    if(dp[num][state]>w){
        dp[num][state]=w;
        pre[num][state]=fa;
        if(!visited[num][state]){
            q.push((Node){num,state});
            visited[num][state]=1;
        }
    }
}
void solve(){
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        int x=now.x/m;
        int y=now.x%m;
        int state=now.y;
        visited[now.x][state]=0;
        for(int i=0;i<4;i++){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(!check(tx,ty))
            continue;
            int to=tx*m+ty;
            modify(to,state,dp[now.x][state]+cost[tx][ty],now.x*1000+state);
        }
        int t=(1<<k)-1-state;
        for(int i=t;i;i=(i-1)&t){
            modify(now.x,i|state,dp[now.x][i]+dp[now.x][state]-cost[x][y],now.x*1000+state);
        }
    }
    int ans=1<<30;
    int now=0;
    for(int i=0;i<n*m;i++){
        if(ans>dp[i][(1<<k)-1]){
            ans=dp[i][(1<<k)-1];
            now=i;
        }
    }
    dfs(now,(1<<k)-1);
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }
    return;
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cost[i][j];
            g[i][j]='.';
        }
    }
    for(int i=0;i<n*m;i++){
        for(int j=0;j<(1<<k);j++){
            dp[i][j]=(1<<30);
        }
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        int num=a*m+b;
        _hash[num]=1<<i;
        modify(num,_hash[num],cost[a][b],-1);
    }
    solve();
    return 0;
}