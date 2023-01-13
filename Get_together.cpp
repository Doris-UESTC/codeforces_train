#include<bits/stdc++.h>
using namespace std;
int n;
double x[100005];
double v[100005];
bool judge(double num){
    double l=x[0]-v[0]*num;
    double r=x[0]+v[0]*num;
    for(int i=1;i<n;i++){
        l=max(l,x[i]-v[i]*num);
        r=min(r,x[i]+v[i]*num);
    }
    return l<=r;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
        cin>>v[i];
    }
    double l=0,r=2e9+1;
    for(int i=0;i<100;i++){
        double mid=l+(r-l)/2;
        if(judge(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<setprecision(10)<<l<<endl;
}