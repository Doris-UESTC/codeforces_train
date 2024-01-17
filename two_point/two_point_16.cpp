//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<int> rec(26,0);
    long long res=0;
    for(int i=0;i<s2.length();i++){
        rec[s2[i]-'a']++;
    }
    int l=0;
    for(int r=0;r<n;r++){
        while(rec[s1[r]-'a']==0){
            rec[s1[l]-'a']++;
            l++;
        }
        rec[s1[r]-'a']--;
        res+=(r-l+1);
    }
    cout<<res<<endl;
}