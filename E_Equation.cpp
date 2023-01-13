#include<bits/stdc++.h>
using namespace std;
int main(){
    double C;
    cin>>C;
    double l=1.0,r=10000000000;
    double ans=0;
    for(int i=0;i<1000000;i++){
        double mid=l+(r-l)/2;
        if(mid*mid+sqrt(mid)>C){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<setprecision(10)<<l<<endl;
}