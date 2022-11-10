#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,y;
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dp[205][1<<7];
int pre[205][1<<7];
int vis[205][1<<7];
char g[205][205];
int n,m,k;
bool check(int x,int y){
    if(x<0||x>=n||y<0||y>=m)
    return false;
    return true;
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

        }
    }
    for(int i=0;i<n*m-1;i++){
        for(int j=0;j<(1<<k);j++){
            dp[i][j]=1<<30;
        }
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;

    }
}