#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int val;
    int lazy;
    item(){
        val=0;
        lazy=0;
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
    void pushdown(int node,int l,int mid,int r){
        if(tree[node].lazy!=0){
            tree[node<<1].lazy=tree[node<<1].lazy+tree[node].lazy;
            tree[(node<<1)+1].lazy=tree[(node<<1)+1].lazy+tree[node].lazy;
            tree[node<<1].val=tree[node<<1].val+(mid-l+1)*tree[node].lazy;
            tree[(node<<1)+1].val=tree[(node<<1)+1].val+(r-mid)*tree[node].lazy;
            tree[node].lazy=0;
        }
    }

    int query(int node, int l,int r, int st ,int sp){  
        if(st>r || sp<l) return 0;    
        if(st>=l&&sp<=r) return tree[node].val;
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1); 
        pushdown(node,st,mid,sp);
        return query(lft,l,r, st,mid) + query(rght,l,r,mid+1,sp);
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].lazy=tree[node].lazy+value;
            tree[node].val=tree[node].val+(sp-st+1)*value;
            return;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node,st,mid,sp);
            update(lft,l,r,st,mid,value);
            update(rght,l,r,mid+1,sp,value);
            tree[node].val=(tree[lft].val+tree[rght].val);
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    Segment_tree st(n+1);
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
            cout<<st.query(1,l+1,r,1,n)<<endl;
        }
    }
    return 0 ;
}