#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        c[1]=a[1];
        for(int i=1;i<=n;i++){
            int res=0;
            for(int j=0;j<=30;j++){
                int s=c[i-1]>>j &1; 
                int t=a[i]>>j &1;
                if(s==1&&t==0)
                res+= 1<<j;   
            }
            c[i]=a[i]^res;
            cout<<res<<" ";
        }
        cout<<""<<endl;
    }
}