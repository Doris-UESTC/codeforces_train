#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> num1;
        vector<int> num2;
        vector<int> num3;
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++){
            int tmp;
            cin>>tmp;
            mp[tmp] +=1;
        }
        for(int i = 0;i < n;i++){
            int tmp;
            cin>>tmp;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==1){
                num2.push_back(i);
            }else if(mp[i]==2){
                num1.push_back(i);
            }else{
                num3.push_back(i);
            }
        }
        for(int i=0;i<min(k,(int)num1.size());i++){
            cout<<num1[i]<<" "<<num1[i]<<" ";
        }
        for(int i=0;i<2*max(0,k-(int)num1.size());i++){
            cout<<num2[i]<<" ";
        }
        cout<<""<<endl;
        for(int i=0;i<min(k,(int)num3.size());i++){
            cout<<num3[i]<<" "<<num3[i]<<" ";
        }
        for(int i=0;i<2*max(0,k-(int)num3.size());i++){
            cout<<num2[i]<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}