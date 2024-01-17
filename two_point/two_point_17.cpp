//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,c;
    cin>>n>>c;
    string s;
    cin>>s;
    int l=0;
    int a_mount=0,b_mount=0;
    int tmp=0;
    int res=0;
    int tmp_a=0;
    for(int r=0;r<n;r++){
        if(s[r]=='a'){
            a_mount++;
        }else if(s[r]=='b'){
            b_mount++;
            tmp+=a_mount;
        }
        while(tmp>c){
            if(s[l]=='a'){
                a_mount--;
                tmp-=b_mount;
            }
			else if(s[l]=='b'){
                b_mount--;
            }
            l++;
        }
        res=max(res,r-l+1);
    }
    cout<<res<<endl;
}