#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> map1(26,0);
        vector<int> map2(26,0);
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<s.length();i++){
            map1[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            int tmp=0;
            map2[s[i]-'a']++;
            map1[s[i]-'a']--;
            for(int j=0;j<26;j++){
                tmp+=(map1[j]>0?1:0);
                tmp+=(map2[j]>0?1:0);
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}