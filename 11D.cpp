/* https://codeforces.com/contest/11/problem/D */
#include<bits/stdc++.h>
using namespace std;
int lowbit(int x){return x&(-x);}
int g[30][30]={0};
long long dp[1<<19][19]={0};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a-1][b-1]=1;
        g[b-1][a-1]=1;
    }
    for(int i=0;i<n;i++){
        dp[1<<i][i]=1;
    }
    long long ans=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(!dp[i][j])
            continue;
            for(int k=0;k<n;k++){
                if(!g[j][k])
                continue;
                if((1<<k)<lowbit(i))
                continue;
                if((1<<k)&i){
                    if((1<<k)==lowbit(i)){
                        ans+=dp[i][j];
                    }
                }
                else{
                    dp[i|(1<<k)][k]+=dp[i][j];
                }
            }
        }
    }
    cout<<(ans-m)/2<<endl;
}