/* https://codeforces.com/contest/371/problem/C 二分答案+贪心*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    ll nb,ns,nc,pb,ps,pc,money;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>money;
    ll rec_b=0,rec_s=0,rec_c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){
            rec_b++;
        }else if(s[i]=='S'){
            rec_s++;
        }else{
            rec_c++;
        }
    }
    ll l=0,r=1e13,ans=0;
    while(l<=r){
        ll mid=(r-l)/2+l;
        ll need_b=rec_b*mid-nb<=0?0:(rec_b*mid-nb)*pb;
        ll need_s=rec_s*mid-ns<=0?0:(rec_s*mid-ns)*ps;
        ll need_c=rec_c*mid-nc<=0?0:(rec_c*mid-nc)*pc;
        ll need=need_b+need_s+need_c;
        if(need<=money){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}