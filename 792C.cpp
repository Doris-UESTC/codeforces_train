#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=0;
    vector<char> rec;
    for(int i=0;i<s.size();i++){
        ans+=(s[i]-'0')%3;
        ans%=3;
    }
    if(ans==0){
    cout<<s<<endl;
    }else if(ans%3==1){
        
    }else{

    }
}