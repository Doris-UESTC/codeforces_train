#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int tmp=x;
        int ans=0;
        vector<int> num;
        vector<int> res;
        while(x!=0){
            num.push_back(x%2);
            x/=2;
        }
        for(int i=0;i<num.size()-1;i++){
            if(num[i]==1){
                res.push_back(tmp);
                tmp-=(1<<i);
                ans++;
            }
        }
        while(tmp){
            res.push_back(tmp);
            tmp/=2;
            ans++;
        }
        cout<<ans<<endl;
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<"\n";
    }
    return 0;
}