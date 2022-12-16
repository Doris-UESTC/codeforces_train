#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int i=0;
    int tmp=0;
    long long ans=0;
    for(int j=0;j<m;j++){
        if(j>0&&b[j]==b[j-1]){
            ans+=tmp;
            continue;
        }else{
            tmp=0;
        }
        if(i==n){
            break;
        }
        while(i<n&&a[i]<b[j]){
            i++;
        }
        while(i<n&&a[i]==b[j]){
            i++;
            tmp++;
        }
        ans+=tmp;
    }
    cout<<ans<<endl;
}