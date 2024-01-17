#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> values;
    void init(int n){
        size=1;
        while(size<n)
        size*=2;
        values.resize(2*size);
    }
    int NEUTRAL_ELEMENT=INT_MIN;
    int merge(int a,int b){
        return max(a,b);
    }
    int single(int v){
        return v;
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
    int find_first(int k,int l,int x,int lx,int rx){
        if(values[x]<k)
        return -1;
        if(rx<=l)
        return -1;
        if(rx-lx==1)
        return lx;
        int m=(lx+rx)/2;
        int res=find_first(k,l,2*x+1,lx,m);
        if(res==-1)
        return find_first(k,l,2*x+2,m,rx);
        return res;
    }   
    int find_first(int k,int l){
        return find_first(k,l,0,0,size);
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
        int x;
        cin>>x;
        st.set(i,x);
    }
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op==1){
            int p,q;
            cin>>p>>q;
            st.set(p,q);
        }else if(op==2){
            int k,l;
            cin>>k>>l;
            cout<<st.find_first(k,l)<<"\n";
        } 
    }
    return 0;
}