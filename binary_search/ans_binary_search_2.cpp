#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<double> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    double l=0,r=1e9;
    double ans=0;
    for(int i=0;i<100;i++){
        double mid=(l+r)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=floor(a[i]/mid);
        }
        if(cnt<k){
            r=mid;
        }else{
			ans=mid;
            l=mid;
        }
    }
    cout<<setprecision(20)<<ans<<endl;
}