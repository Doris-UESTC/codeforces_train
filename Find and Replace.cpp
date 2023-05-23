#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<int> rec(26,-1);
        int n;
        cin>>n;
        string s;
        cin>>s;
        int j=0;
        for(;j<n;j++){
            if(rec[s[j]-'a']==-1){
                rec[s[j]-'a']=j%2;
            }else{
                if(rec[s[j]-'a']!=j%2){
                    cout<<"NO"<<endl;
                    break;
                }else{
                    continue;
                }
            }
        }
        if(j==n)
        cout<<"YES"<<endl;
    }
    return 0;
}