#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    int ans=0;
    long long tmp=0;
    for(int r=0;r<n;r++){
        tmp+=a[r];
        while(l<n&&tmp>s){
            tmp-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
}