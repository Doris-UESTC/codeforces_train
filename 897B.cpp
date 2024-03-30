#include<bits/stdc++.h>
using namespace std;
bool judge(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i]==s[s.length()-1-i])
        continue;
        else
        return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int len;
        cin>>len;
        string s;
        cin>>s;
        int freedom=0;
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[s.length()-1-i])
            freedom++;
        }
        for(int i=0;i<freedom;i++){
            cout<<0;
        }
        int cnt=0;
        for(int i=freedom;i<len-freedom+1;i++){
            if(cnt%2==0)
            cout<<1;
            else 
            cout<<(len%2==0?0:1);
            cnt++;
        }
        for(int i=len-freedom+1;i<len+1;i++){
            cout<<0;
        }
        cout<<"\n";
    }
    return 0;
}