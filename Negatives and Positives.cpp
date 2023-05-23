#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        int tmp=0;
        int min_num=INT_MAX;
        int zero=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=abs(a[i]);
            min_num=min(abs(a[i]),min_num);
            if(a[i]<0)
            tmp++;
            else if(a[i]==0)
            zero++;
        }
        if(tmp%2==0)
        cout<<sum<<endl;
        else{
            if(zero>0)
            cout<<sum<<endl;
            else
            cout<<sum-2*min_num<<endl;
        }
    }
    return 0;
}