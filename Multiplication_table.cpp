#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
bool is_found=false;
bool judge(int num){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(num%i==0){
            ans+=min(n,num/i-1);
        }else{
            ans+=min(n,num/i);
        }
    }
    return ans<k;
}
int32_t main(){
    cin>>n>>k;
    int l=1,r=n*n,tmp_ans;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(judge(mid)){ 
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l-1<<endl;
}