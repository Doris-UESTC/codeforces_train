#include<bits/stdc++.h>
using namespace std;
struct segtree{
    int size;
    vector<int> mmin;
    void init(int n){
        size=1;
        while(size<n)
        size*=2;
        mmin.assign(2*size,0LL);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            mmin[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        mmin[x]=min(mmin[2*x+1],mmin[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    long long min_f(int l,int r,int x,int lx,int rx){
        if(lx>=r||l>=rx) return INT_MAX;
        if(lx>=l&&rx<=r) return mmin[x];
        int m=(lx+rx)/2;
        int s1=min_f(l,r,2*x+1,lx,m);
        int s2=min_f(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }
    long long min_f(int l,int r){
        return min_f(l,r,0,0,size);
    }   
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        st.set(i,v);
    }
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.min_f(l,r)<<"\n";
        }
    }
    return 0;
}