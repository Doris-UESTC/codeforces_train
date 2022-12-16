#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct coprime
{
    vector<ll> s,values={0};
    void push(ll x)
    {
        s.push_back(x);
        values.push_back(__gcd(values.back(),x));
    }
    ll pop()
    {
        ll res=s.back();
        s.pop_back();
        values.pop_back();
        return res;
    }
    ll gcd()
    {
        return values.back();
    }
    bool empty()
    {
        return s.empty();
    }
};
coprime s1,s2;
void add(ll x)
{
    s2.push(x);
}
void remove()
{
    if(s1.empty())
    {
        while(!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool good()
{
    ll g1=s1.gcd();
    ll g2=s2.gcd();
    //cout<<g1<<" "<<g2<<" ";
    return __gcd(g1,g2)==1;
}
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // ll n;
    // cin>>n;
    // vector<ll> a(n);
    // for(int i=0;i<n;i++)
    //     cin>>a[i];
    // ll res=INT_MAX,l=0,r=0;
    // while(r<n)
    // {
    //     add(a[r]);
    //     while(good())
    //     {
    //         remove();
    //         res=min(res,r-l+1);
    //         l++;
    //     }
    //     r++;
    // }
    // if(res==INT_MAX)
    //     res=-1;
    // cout<<res<<"\n";
    cout<<__gcd(0,1)<<"\n";
}