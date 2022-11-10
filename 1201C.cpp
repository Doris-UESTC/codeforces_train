/* https://codeforces.com/problemset/problem/1201/C 二分查找 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200050]={0};
ll n,k;
bool check(ll num){
    long long tmp=0;
    for(int i=n/2;i<n;i++){
        tmp+=(num-a[i]>0?num-a[i]:0);
    }
    return tmp<=k;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long l=0,r=1e12,ans=0;
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
    return 0;
}