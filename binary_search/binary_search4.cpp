#include<bits/stdc++.h>
using namespace std;
int find_left(vector<int> &a,int x){
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
int find_right(vector<int> &a,int x){
    int l=-1,r=a.size();
    while(l+1<r){
        int mid=(r-l)/2+l;
        if(a[mid]<=x){
            l=mid;
        }else{
            r=mid;
        }
    }
    return l+1;
}
int main(){
    int n;
    cin>>n;
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    sort(val.begin(),val.end());
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int left_val,right_val;
        cin>>left_val>>right_val;
        cout<<find_right(val,right_val)-find_left(val,left_val)+1<<endl;
    }
}