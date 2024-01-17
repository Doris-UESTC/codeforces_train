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
    int NEUTRAL_ELEMENT=0;
    int merge(int a,int b){
        return a+b;
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
    int find(int k,int x,int lx,int rx){
        if(rx-lx==1){
            return lx;
        }
        int m=(lx+rx)/2;
        int sl=values[2*x+1];
        if(k<sl){
            return find(k,2*x+1,lx,m);
        }else{
            return find(k-sl,2*x+2,m,rx);
        }
    }   
    int find(int k){
        return find(k,0,0,size);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.set(i,a[i]);
    }
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op==1){
            int v;
            cin>>v;
            a[v]=1-a[v];
            st.set(v,a[v]);
        }else if(op==2){
            int k;
            cin>>k;
            cout<<st.find(k)<<"\n";
        } 
    }
    return 0;
}