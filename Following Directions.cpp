#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x=0,y=0;
        int i=0;
        for(;i<s.length();i++){
            if(s[i]=='U'){
                y++;
            }else if(s[i]=='R'){
                x++;
            }else if(s[i]=='D'){
                y--;
            }else if(s[i]=='L'){
                x--;
            }
            if(x==1&&y==1){
                cout<<"YES"<<endl;
                break;
            }
        }   
        if(i==s.length())
        cout<<"NO"<<endl;
    }
    return 0;
}