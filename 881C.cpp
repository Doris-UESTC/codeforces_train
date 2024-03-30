#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long num;
        cin>>num;
        long long ans=0;
        while(num!=0){
            ans+=num;
            num/=(long long)2;
        }
        cout<<ans<<endl;
    }
    return 0;
}