#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <set>

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=2;
        while(1){
            set<long long> s;
            for(int i=0;i<n;i++){
                s.insert(a[i]%ans);
            }
            if(s.size()==2){
                cout<<ans<<endl;
                break;
            }
            ans*=2;
        }
    }
    return 0;
}