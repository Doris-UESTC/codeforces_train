#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int dp[1005][1005];
int c;

int main(){
    int n,m;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int x=0,y=0;
    long long tmp=a[0][0];
    long long ans=tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long tmp_num=a[i][j]-c*(i+j);
            if(tmp_num<tmp){
                ans=a[i][j]+a[x][y]+c*abs(i-x)*abs(j-y);
                x=i;
                y=j;
                tmp=tmp_num;
            }
        }
    }
    cout<<ans<<endl;
}