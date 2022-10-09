/* https://codeforces.com/problemset/problem/1251/D 采用二分查找*/
#include<bits/stdc++.h>
using namespace std;
bool solve(int mid,vector<vector<int> > interval,long long s){
    long long ans=s;
    int count=0;
    for(int i=interval.size()-1;i>=0;i--){
        if(mid<=interval[i][1]&&ans>=mid-interval[i][0]){
            ans-=max(0,mid-interval[i][0]);
            count++;
        }
    }
    if(count>=interval.size()/2+1&&ans<=s){
        return true;
    }else 
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,s;
        cin>>n>>s;
        vector<vector<int> > interval(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>interval[i][0]>>interval[i][1];
            s-=interval[i][0];
        }
        sort(interval.begin(),interval.end());
        long long left=0,right=1e9;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(solve(mid,interval,s)){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        cout<<right<<endl;
    }
    return 0;
}