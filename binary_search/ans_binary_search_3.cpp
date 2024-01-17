#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int l=1,r=INT_MAX-1;
    int ans=0;
    while(l<=r){
        int mid=(r-l)/2+l;
		int tmp=mid-min(x,y);
        if(tmp<0){
            l=mid+1;
            continue;
        }
        if(tmp/x+tmp/y+1>=n){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}