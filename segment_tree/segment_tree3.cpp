#include<bits/stdc++.h>
using namespace std;
struct item
{
    int m,c;
};
struct segtree{
    int size;
    vector<item> values;
    void init(int n){
        size=1;
        while(size<n)
        size*=2;
        values.resize(2*size);
    }
    item NEUTRAL_ELEMENT={INT_MAX,0};
    item merge(item a,item b){
        if(a.m<b.m) return a;
        if(a.m>b.m) return b;
        return {a.m,a.c+b.c};
    }
    item single(int v){
        return {v,1};
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            values[x]=single(v);
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    item max_f(int l,int r,int x,int lx,int rx){
        if(lx>=r||l>=rx) return NEUTRAL_ELEMENT;
        if(lx>=l&&rx<=r) return values[x];
        int m=(lx+rx)/2;
        item s1=max_f(l,r,2*x+1,lx,m);
        item s2=max_f(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item max_f(int l,int r){
        return max_f(l,r,0,0,size);
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
            item tmp_ans=st.max_f(l,r);
            cout<<tmp_ans.m<<" "<<tmp_ans.c<<"\n";
        }
    }
    return 0;
}