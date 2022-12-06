#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> t(n);
    vector<int> z(n);
    vector<int> y(n);
    for(int i=0;i<n;i++){
        cin>>t[i]>>z[i]>>y[i];
    }
    int l=0,r=1e9;
    int ans=0;
    while(l<=r){
        int cnt=0;
        int mid=(r-l)/2+l;
        for(int i=0;i<n;i++){
            if(t[i]*z[i]>mid){
                cnt+=(mid/t[i]);
            }else if(t[i]*z[i]+y[i]<mid){
                int tmp=mid/(t[i]*z[i]+y[i]);
                cnt+=(tmp*z[i])+min((mid-tmp*(t[i]*z[i]+y[i]))/t[i],z[i]);
            }else{
                cnt+=z[i];
            }
        }
        if(cnt<=m){
            l=mid+1;
        }else{
            ans=mid;
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}   