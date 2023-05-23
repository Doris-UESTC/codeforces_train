#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[20][20];
int dp[1<<20];
int32_t main(){
    int N;
    cin>>N;
    int m=1<<N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<N;j++){
            if(((i>>j)&1)==0)
            continue;
            for(int k=j+1;k<N;k++){
                if(((i>>k)&1)==0)
                continue;
                dp[i]+=a[j][k];
            }
        }
        for(int j=i&(i-1);j;j=(j-1)&i){
            dp[i]=max(dp[i],dp[j]+dp[j^i]);
        }
    }
    cout<<dp[m-1]<<endl;
}