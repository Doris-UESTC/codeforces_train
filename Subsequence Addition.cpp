#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[200005];
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        sort(c,c+n);
        if(n==1)
        cout<<(c[0]==1?"YES":"NO")<<endl;
        else{
            if(c[0]!=1||c[1]!=1){
                cout<<"NO"<<endl;
            }
            else{
                int i=2;
                int sum=c[0]+c[1];
                for(;i<n;i++){
                    if(c[i]>sum){
                        cout<<"NO"<<endl;
                        break;
                    }
                    sum+=c[i];
                }
                if(i==n)
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
