#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int r_b,r_s,r_c;
int n_b,n_s,n_c;
int p_b,p_s,p_c;
int r;
bool judge(int x){
    int need_b=max(0LL,x*r_b-n_b);
    int need_s=max(0LL,x*r_s-n_s);
    int need_c=max(0LL,x*r_c-n_c);
    int cost=need_b*p_b+need_s*p_s+need_c*p_c;
    return cost<=r;
}
int32_t main(){
    cin>>s;
    cin>>n_b>>n_s>>n_c;
    cin>>p_b>>p_s>>p_c;
    cin>>r;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B') 
        r_b++;
        if(s[i]=='S')
        r_s++;
        if(s[i]=='C') 
        r_c++;
    }
    int l=0,r=1e13;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(judge(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}