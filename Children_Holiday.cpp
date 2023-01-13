#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[1005],z[1005],y[1005];
int n,m;
bool judge(int num){
    int tmp=0;
    for(int i=0;i<n;i++){
        tmp+=z[i]*(num/(t[i] * z[i] + y[i]));
        int res=num%(t[i] * z[i] + y[i]);
        if(res>=(t[i]*z[i]))
        tmp+=z[i];
        else
        tmp+=res/t[i];
    }
    return tmp>=m;
}
int32_t main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>t[i]>>z[i]>>y[i];
    }
    int l=-1,r=2e9+1;
    int ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(judge(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        int tmp=0;
        int cp_ans=ans;
        tmp+=z[i]*(cp_ans/(t[i] * z[i] + y[i]));
        int num=cp_ans%(t[i] * z[i] + y[i]);
        if(num>=(t[i]*z[i]))
        tmp+=z[i];
        else
        tmp+=num/t[i];
        cout<<min(tmp,m)<<" ";
        m-=min(tmp,m);
    }
}