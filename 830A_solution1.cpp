/* https://codeforces.com/problemset/problem/830/A */
#include<bits/stdc++.h>
using namespace std;
int a[10000];
int b[10000];
int main(){
    int n,k,p;
    cin>>n>>k>>p;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+k);
    int len=k-n+1;
    long long ans=1e18,maxx=0;
    for(int start=0;start<len;start++){
        maxx=0;
        for(int i=start,j=0;j<n;i++,j++){
            if(abs(b[i]-p)+abs(a[j]-b[i])>maxx){
                maxx=abs(b[i]-p)+abs(a[j]-b[i]);
            }
        }
        ans=min(ans,maxx);
    }
    cout<<ans<<endl;
    return 0;
}