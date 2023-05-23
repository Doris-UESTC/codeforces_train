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
        int tmp=0;
        int l=0,r=n-1;
        while(l<=r){
            if(s[l]=='0'&&s[r]=='1'){
                tmp+=2;
                l++;
                r--;
            }else if(s[l]=='1'&&s[r]=='0'){
                tmp+=2;
                l++;
                r--;
            }else{
                break;
            }
        }
        cout<<n-tmp<<endl;
    }
    return 0;
}