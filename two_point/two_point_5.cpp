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
    long long tmp=0;
    int ans=INT_MAX;
    for(int r=0;r<n;r++){
        tmp+=a[r];
        bool judge=true;
        while(l<n&&tmp>=s){
            judge=false;
            tmp-=a[l];
            l++;
        }
        if(!judge)
        ans=min(ans,r-l+2);
    }
    if(ans==INT_MAX){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}