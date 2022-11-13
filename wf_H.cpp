#include<bits/stdc++.h>
using namespace std;
int l[1000005],r[1000005],tp[1000005],id[1000005];
int n;
bool check(){
    int sum=0;
    for(int i=0;i<n;i++){
        sum-=r[id[i]];
        if(sum<0)
        return false;
        sum+=l[id[i]];
    }
    return sum==0;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int x=0,y=0;
        for(char ch:s){
            if(ch=='(')x++;
            else if(x>0)x--;
            else y++;
        }
        l[i]=x;
        r[i]=y;
        if(y==0){
            tp[i]=1;
        }else if(x==0){
            tp[i]=4;
        }else if(x>y){
            tp[i]=2;
        }else{
            tp[i]=3;
        }
        id[i]=i;
    }
    sort(id,id+n,[&](int a,int b){
        if(tp[a]!=tp[b])
        return tp[a]<tp[b];
        if(tp[a]==2){
            if(r[a]!=r[b])
            return r[a]<r[b];
            return l[a]>l[b];
        }
        if(tp[a]==3){
            return l[a]>l[b];
        }
        return false;
    });
    if(check()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}