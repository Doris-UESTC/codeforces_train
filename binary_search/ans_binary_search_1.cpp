// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     long long ans=0;
//     long long w,h,n;
//     cin>>w>>h>>n;
//     long long l=max(h,w),r=1;
//     while((r/w)*(r/h)<n){
//         r*=2;
//     }
//     while(l<=r){
//         long long mid=(r+l)/2;
//         if((mid/w)>=n/(mid/h)){
// 			ans=mid;
//             r=mid-1;
//         }else{
//             l=mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ans=0;
    long long w,h,n;
    cin>>w>>h>>n;
    long long l=max(h,w),r=1;
    while((r/w)*(r/h)<n){
        r*=2;
    }
    while(l<=r){
        long long mid=(r+l)/2;
        if((mid/w)>=(n-1)/((mid)/h)+1){
			ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}