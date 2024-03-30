#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> num;
        while(n!=0){
            num.push_back(n%2);
            n/=2;
        }
        if((int)num.size() > k){
            cout<<(1<<k)<<endl;
            continue;
        }
        int ans=1;
        int idx=(int)num.size()-1;
        ans += (1<<idx);
        for(int i=idx-1; i>=0; i--){
            if(num[i]==1){
                ans+=(1<<i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}