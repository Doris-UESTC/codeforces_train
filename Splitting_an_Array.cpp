#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100005];
bool is_ans=false;
bool judge(double num){
    int tmp=0;
    int c=1;
    for(int i=0;i<n;i++){
        if(tmp+a[i]>num){
            tmp=a[i];
            c++;
        }else{  
            tmp+=a[i];
        }
    }
    return c<=k;
}
int32_t main(){
    cin>>n>>k;
    int maxV=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxV=max(maxV,a[i]);
    }
    int l=maxV,r=2e15,ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(judge(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}