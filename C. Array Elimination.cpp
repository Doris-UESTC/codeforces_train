#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[200005]={0};
        int rec[35]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=30;j++){
                int tmp=a[i]>>j &1;
                rec[j]+=tmp;
            }
        }
        int ans=0;
        for(int i=0;i<=30;i++){
            if(rec[i]==0)
            continue;
            if(ans==0)
            ans=rec[i];
            else
            ans=gcd(ans,rec[i]);
        }
        if(ans==0){
            for(int k=1;k<=n;k++){
                cout<<k<<" ";
            }
        }else{
            vector<int> aaa;
            for(int k=1;k*k<=ans;k++){
                if(ans%k==0&&ans!=k*k){
                    cout<<k<<" ";
                    aaa.push_back(ans/k);
                }else if(ans==k*k)
                cout<<k<<" ";
            }
            for(int i=aaa.size()-1;i>=0;i--){
                cout<<aaa[i]<<" ";

            }
        }
        cout<<""<<endl;
    }
}