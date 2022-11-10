/* https://codeforces.com/problemset/problem/549/H */
#include<bits/stdc++.h>
using namespace std;
double min(double a,double b){
    return a<=b?a:b;
}
double max(double a,double b){
    return a>=b?a:b;
}
int main(){
    double a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    double ans=0;
    double l=0,r=1e9;
    for(int i=0;i<1000000;i++){
        double mid=(r+l)/2.0;
        double a1=a-mid,b1=b-mid,c1=c-mid,d1=d-mid;
        double a2=a+mid,b2=b+mid,c2=c+mid,d2=d+mid;
        double x1=min(min(a1*d1,a1*d2),min(a2*d1,a2*d2));
        double x2=min(min(b1*c1,b1*c2),min(b2*c1,b2*c2));
        double t1=max(max(a1*d1,a1*d2),max(a2*d1,a2*d2));
        double t2=max(max(b1*c1,b1*c2),max(b2*c1,b2*c2));
        if(x1<=t2&&x2<=t1){
            ans=mid;
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}