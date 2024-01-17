//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/H
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m,s,a_val,b_val;
    cin>>n>>m>>s>>a_val>>b_val;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int l1=min(s/a_val,n)-1;
    int tmp=(l1+1)*a_val;
    int cost=0;
    for(int i=0;i<=l1;i++){
        cost+=a[i];
    }
    int res=cost;
    for(int i=0;i<m;i++){
        cost+=b[i];
        tmp+=b_val;
        while(tmp>s&&l1>=0){
            tmp-=a_val;
            cost-=a[l1];
            l1--;
        }
        if(tmp<=s){
            res=max(res,cost);
        }
    }
    cout<<res<<endl;
}