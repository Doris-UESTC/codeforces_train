//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
	for(int i=0;i<n;i++){
	    cin>>b[i];
	}
    int l=0;
    int res=0;
    int tmp=0;
    int reward_tmp=0;
    for(int r=0;r<n;r++){
        tmp+=a[r];
        reward_tmp+=b[r];
        while(tmp>s){
            tmp-=a[l];
            reward_tmp-=b[l];
            l++;
        }
        res=max(res,reward_tmp);
    }
    cout<<res<<endl;
}