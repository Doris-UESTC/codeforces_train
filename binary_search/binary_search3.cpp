#include<bits/stdc++.h>
using namespace std;
int search(vector<int> &a,int x){
    int l=-1,r=a.size();
    while(l+1<r){
        int mid=(r-l)/2+l;
        if(a[mid]>=x){
            r=mid;
        }else{
            l=mid;
        }
    }
    return r+1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<k;i++){
        int search_val;
        cin>>search_val;
        cout<<search(val,search_val)<<endl;
    }
       
}