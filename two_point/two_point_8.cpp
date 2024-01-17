#include<bits/stdc++.h>
using namespace std;
int rec[100005]={0};
int main(){
    int n;
    long long s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    int num=0;
    long long ans=0;
    int l=0;
    for(int r=0;r<n;r++){
        if(rec[a[r]]==0){
            num++;
        }
        rec[a[r]]++;
        while(num>s){
            rec[a[l]]--;
            if(rec[a[l]]==0){
                num--;
            }
            l++;
        }
        ans+=(r-l+1);
    }
    cout<<ans<<endl;
}