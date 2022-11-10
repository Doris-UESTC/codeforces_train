/* https://codeforces.com/contest/670/problem/D1 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll a[1050]={0},b[1050]={0};
bool check(ll num){
    ll tmp=0;
    for(int i=0;i<n;i++){
        tmp+=(num*a[i]-b[i]>=0?num*a[i]-b[i]:0);
    }
    return tmp<=k;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll l=0,r=1e12,ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}
