/* https://codeforces.com/contest/550/problem/B */
#include<bits/stdc++.h>
using namespace std;
int num[20]={0};
int main(){
    int n, l, r, x;
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        int tmp=i;
        long long sum=0;
        int max_num=INT_MIN;
        int min_num=INT_MAX;
        int count=0;
        while(tmp){
            if(tmp&1){
                sum+=num[count];
                max_num=max(max_num, num[count]);
                min_num=min(min_num, num[count]);
            }
            tmp>>=1;
            count++;
        }
        if(sum>=l&&sum<=r&&max_num-min_num>=x){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}