#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define Mat vector<vi>
#define Mod 1000000007
Mat operator*(Mat a,Mat b){
    int n=a.size();
    Mat ans(n,vi(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%Mod)%Mod;
            }
        }
    }
    return ans;
}
Mat operator^(Mat a,int b){
    int n=a.size();
    Mat ans(n,vi(n,0));
    for(int i=0;i<n;i++){
        ans[i][i]=1;
    }
    while(b){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
int32_t main(){
    int n,k;
    cin>>n>>k;
    Mat mat(n,vi(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            mat[i][j]=tmp;
        }
    }
    int ans=0;
    Mat res=mat^k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=(ans+res[i][j])%Mod;
        }
    }
    cout<<ans<<endl;
}