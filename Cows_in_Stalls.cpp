#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
int n,k;
bool judge(int num){
    int start=a[0];
    int c=1;
    for(int i=1;i<n;i++){
        if(a[i]-start>=num){
            start=a[i];
            c++;
        }
        if(c>=k)
        return true;
    }
    return false;
}
int32_t main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(judge(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}