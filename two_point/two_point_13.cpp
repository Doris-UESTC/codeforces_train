//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    long long res=0;
    for(int r=1;r<n;r++){
        while(a[r]-a[l]>d){
            l++;
        }
        res+=l;
    }
    cout<<res<<endl;
}