#include<bits/stdc++.h>
using namespace std;
int n,d;
double a[100005];
double b[100005];
double sum[100005];
double min_sum[100005];
int idx[100005];
int ans_l,ans_r;
bool judge(double x){
    for(int i=1;i<=n;i++){
        b[i]=a[i]-x;
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+b[i];
        if(min_sum[i-1]>sum[i]){
            min_sum[i]=sum[i];
            idx[i]=i;
        }else{
            min_sum[i]=min_sum[i-1];
            idx[i]=idx[i-1];
        }
    }
    for(int i=d;i<=n;i++){
        if(sum[i]>=min_sum[i-d]){
            ans_l=idx[i-d]+1;
            ans_r=i;
            return true;
        }
    }
	return false;
}
int main(){
    cin>>n>>d;
    double l=INT_MAX,r=INT_MIN;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    for(int i=0;i<500;i++){
        double mid=l+(r-l)/2;
        if(judge(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
	cout<<ans_l<<" "<<ans_r<<endl;
}
