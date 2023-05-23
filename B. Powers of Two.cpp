#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define int long long
int a[200005];
int rec[35];
int32_t main(){
    unordered_map<int,int> mp;
    int n;
    cin>>n;
    for(int i=1;i<=30;i++){
        rec[i]=1<<i;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=30;j++){
            res+=mp[rec[j]-a[i]];
        }
        mp[a[i]]++;
    }
    cout<<res<<endl;
    return 0;
}