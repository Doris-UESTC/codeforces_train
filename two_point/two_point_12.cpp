//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    ll sum=0;
    ll res=0;
    for(int r=0;r<n;r++){
        sum+=a[r];
        while(sum>s){
            sum-=a[l];
            l++;
        }
        res+=(long long)(r-l+1)*(r-l+2)/2;
    }
    cout<<res<<endl;
}