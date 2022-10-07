/*https://codeforces.com/problemset/problem/1426/F*/
#include<bits/stdc++.h>
long long rec[200050][3]={0};
long long ans=0;
long long threepow[200050]={1};
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int len=s.length();
    for(int i=1;i<=len;i++){
        threepow[i]=3*threepow[i-1];
        threepow[i]%=1000000007;
    }
    rec[0][0]=s[0]=='a'?1:0;
    rec[0][1]=s[0]=='c'?1:0;
    rec[0][2]=s[0]=='?'?1:0;
    for(int i=1;i<len;i++){
        rec[i][0]=rec[i-1][0]+(s[i]=='a'?1:0);
        rec[i][1]=rec[i-1][1]+(s[i]=='c'?1:0);
        rec[i][2]=rec[i-1][2]+(s[i]=='?'?1:0);
    }
    for(int i=1;i<len;i++){
        if(s[i]=='b'||s[i]=='?'){
            int left_a=rec[i-1][0];
            int right_c=rec[len-1][1]-rec[i][1];
            int left_q=rec[i-1][2];
            int right_q=rec[len-1][2]-rec[i][2];
            if(left_q+right_q>=0)
            ans+=(long long)left_a*right_c*threepow[left_q+right_q];
            ans%=1000000007;
            if(left_q+right_q>=1)
            ans+=(long long)left_a*right_q*threepow[left_q+right_q-1];
            ans%=1000000007;
            if(left_q+right_q>=1)
            ans+=(long long)left_q*right_c*threepow[left_q+right_q-1];
            ans%=1000000007;
            if(left_q+right_q>=2)
            ans+=(long long)left_q*right_q*threepow[left_q+right_q-2];
            ans%=1000000007;
        }
    }
    cout<<ans<<endl;
}