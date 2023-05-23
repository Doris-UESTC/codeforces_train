#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int prefix[200005];
int32_t main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>a[i];
            prefix[i+1]=prefix[i]+a[i];
        }
        for(int i=0;i<q;i++){
            int l,r,value;
            cin>>l>>r>>value;
            int sum=prefix[r]-prefix[l-1];
            int tmp=prefix[n]-sum+value*(r-l+1);
            if(tmp%2==0){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}