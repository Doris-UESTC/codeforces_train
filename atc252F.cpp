#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > p_q;
long long a[200050];
int main(){
    long long n,l;
    cin>>n>>l;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        p_q.push(a[i]);
    }
    long long ans=0;
    if(l-sum){
        p_q.push(l-sum);
    }
    while(p_q.size()>1){
        long long x=p_q.top();
        p_q.pop();
        long long y=p_q.top();
        p_q.pop();
        ans+=(x+y);
        p_q.push(x+y);
    }
    cout<<ans<<endl;
}