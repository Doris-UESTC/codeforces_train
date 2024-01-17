#include<bits/stdc++.h>
using namespace std;
bool search(vector<int> &a,int x){
    int l=0,r=a.size()-1;
    while(l<=r){
        int mid=(r-l)/2+l;
        if(a[mid]==x){
            return true;
        }else if(a[mid]<x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return false;
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
        if(search(val,search_val)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }   
}