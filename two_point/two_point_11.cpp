//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    ll p;
    cin>>n>>p;
    vector<ll> a(2*n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i+n]=a[i];
        sum+=a[i];
    }
    int l=0,r=0;
    ll res=p/sum*(ll)n;
    sum=p%sum;
    if(sum==0){
        cout<<1<<" "<<res<<endl;
        return 0;
    }
    int tmp_res=INT_MAX;
    int tmp_index=0;
    for(int l=0;l<n;l++){
        long long tmp=0;
        for(int r=l;r<n+l;r++){
            tmp+=a[r];
            if(tmp>=sum){
                if(r-l+1<tmp_res){
                    tmp_index=l;
                    tmp_res=r-l+1;
                }
                break;
            }
        }
    }
    cout<<tmp_index+1<<" "<<res+tmp_res<<endl;
}