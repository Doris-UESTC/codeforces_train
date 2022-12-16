#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct stack{
    vector<ll> s,smin={LLONG_MAX},smax={LLONG_MIN};
    void push(ll val){
        s.push_back(val);
        smin.push_back(::min(smin.back(),val));
        smax.push_back(::max(smax.back(),val));
    }
    ll pop(){
        ll res=s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }
    bool empty(){
        return s.empty();
    }
    ll min(){
        return smin.back();
    }
    ll max(){
        return smax.back();
    }
};
::stack s1,s2;
ll k;

void add(ll val){
    s2.push(val);
}

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good(){ 
    ll mmin=min(s1.min(),s2.min());
    ll mmax=max(s1.max(),s2.max());
    return mmax-mmin<=k;
}

int main(){
    int n;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    int l=0;
    ll res=0;
    for(int r=0;r<n;r++){
        add(a[r]);
        while(!good()){
            remove();
            l++;
        }
        res+=r-l+1;
    }
    cout<<res<<endl;
    return 0;
}