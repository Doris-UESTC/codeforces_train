/* https://codeforces.com/problemset/problem/912/E */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> val[2];
const ll INF=1e18;
ll n,p[50],k;
bool check(ll num){
    int ans=0;
    for(int i=val[0].size()-1,j=0;i>=0;i--){
        while(j<val[1].size()&&val[1][j]<=num/val[0][i]){
            j++;
        }
        ans+=j;
    }
    return ans>=k;
}
void dfs(int type,int pos,ll num){
    val[type].push_back(num);
    for(int i=pos;i<n;i+=2){
        if(INF/p[i]>=num)
        dfs(type,i,num*p[i]);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cin>>k;
    dfs(0,0,1);
    dfs(1,1,1);
    sort(val[0].begin(),val[0].end());
    sort(val[1].begin(),val[1].end());
    /*for(int i=0;i<val[0].size();i++){
        cout<<val[0][i]<<" ";
    }
    cout<<""<<endl;
    for(int i=0;i<val[1].size();i++){
        cout<<val[1][i]<<" ";
    }
    cout<<""<<endl;*/
    ll l=0,r=1e18,ans=0;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}