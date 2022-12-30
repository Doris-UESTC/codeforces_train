#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD_NUM 1000000007
struct item{
    int val;
    int lazy;
    item(){
        val=1;
        lazy=1;
    }
};
item element=item();
class Segment_tree{
    public:
    vector<item> tree;
    Segment_tree(){}
    Segment_tree(int n){
        tree.assign(4*n,element);
    }
    void build(int x,int lx,int rx){
        if(lx==rx){
            tree[x].val=1;
            tree[x].lazy=1;
            return;
        }else{
            int m=(lx+rx)/2;
            build(2*x,lx,m);
            build(2*x+1,m+1,rx);
            tree[x].val=(tree[2*x].val+tree[2*x+1].val)%MOD_NUM;
            tree[x].lazy=1;
        }
    }
    void pushdown(int node){
        if(tree[node].lazy!=1){
            tree[node<<1].lazy=tree[node<<1].lazy*tree[node].lazy%MOD_NUM;
            tree[(node<<1)+1].lazy*=tree[(node<<1)+1].lazy*tree[node].lazy%MOD_NUM;
            tree[node<<1].val=tree[node<<1].val*tree[node].lazy%MOD_NUM;
            tree[(node<<1)+1].val=tree[(node<<1)+1].val*tree[node].lazy%MOD_NUM;
            tree[node].lazy=1;
        }
    }

    int query(int node, int l,int r, int st ,int sp){  
        if(st>r || sp<l) return 0;    
        if(st>=l&&sp<=r) return tree[node].val%MOD_NUM;
        // pushdown(node);
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1); 
        return ((query(lft,l,r, st,mid) + query(rght,l,r,mid+1,sp))%MOD_NUM)*tree[node].lazy%MOD_NUM;
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].lazy=tree[node].lazy*value%MOD_NUM;
            tree[node].val=tree[node].val*value%MOD_NUM;
            return;
        }
        else{
            // pushdown(node);
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            update(lft,l,r,st,mid,value);
            update(rght,l,r,mid+1,sp,value);
            tree[node].val=(tree[lft].val+tree[rght].val)%MOD_NUM;
            tree[node].val=(tree[node].val*tree[node].lazy)%MOD_NUM;
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    Segment_tree st(n+1);
    st.build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,v;
            cin>>l>>r>>v;
            st.update(1,l+1,r,1,n,v);
        }else if(op==2){
            int l,r;
            cin>>l>>r;
            cout<<st.query(1,l+1,r,1,n)%MOD_NUM<<endl;
        }
    }
    return 0 ;
}