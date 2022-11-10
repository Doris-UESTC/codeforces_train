/*  */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100050]={0},b[100050]={0};
ll add[100050]={0};
bool check(ll mid,ll n,ll m,ll w){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    ll now=0;
    memset(add,0,sizeof(add));
    for(int i=0;i<n;i++){
        now+=add[i];
        b[i]+=now;
        if(b[i]<mid){
            int go=mid-b[i];
            b[i]+=go;
            add[100005>i+w?i+w:100005]-=go;
            now+=go;
            m-=go;
            if(m<0)
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]<mid)
        return false;
    }
    return true;
}
int main(){
    ll n,m,w;
    cin>>n>>m>>w;
    ll min_num=1e9;
    ll max_num=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        min_num=a[i]>=min_num?min_num:a[i];
        max_num=a[i]<=max_num?max_num:a[i];
    }
    ll l=min_num,r=max_num+m,ans=min_num;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(check(mid,n,m,w)){
            ans=ans>mid?ans:mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
