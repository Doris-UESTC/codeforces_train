#include<bits/stdc++.h>
using namespace std;
double a[100005],b[100005],tmp[100005];
int n,k;
bool judge(double x){
    double sum=0;
    for(int i=0;i<n;i++){
        tmp[i]=a[i]-b[i]*x;
    }
    sort(tmp,tmp+n);
    for(int i=n-1;i>=n-k;i--){
        sum+=tmp[i];
    }
    return sum<=0;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    double l=-1,r=1e12,ans=0;
    for(int i=0;i<100;i++){
        double mid=(r+l)/2;
        if(judge(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<setprecision(10)<<r<<endl;
}