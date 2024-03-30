#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string tmp;
        map<char,int> mp;
        for(int i=0;i<3;i++){
            cin>>tmp;
            mp[tmp[0]]++;
            mp[tmp[1]]++;
            mp[tmp[2]]++;
        }
        if(mp['A']==2){
            cout<<"A"<<endl;
        }else if(mp['B']==2){
            cout<<"B"<<endl;
        }else{
            cout<<"C"<<endl;
        }

    }
    return 0;
}