#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int prefix[200005];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prefix[i+1]=prefix[i]+a[i];
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        cout<<"? "<<(mid-l+1)<<' ';
        for(int i=l;i<=mid;i++){
            cout<<i<<' ';
        }
        cout<<endl<<flush;
        int x=0;
        cin>>x;
        if(prefix[mid+1]-prefix[l]==x){
            l=mid+1;
        }else{
            r=mid-1;
            ans=mid;
        }
    }
    cout<<"! "<<ans<<endl<<flush;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}