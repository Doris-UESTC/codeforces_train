#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int val;
    int add_lazy;
    int assign_lazy;
    item(){
        val=0;
        add_lazy=0;
        assign_lazy=LLONG_MAX;
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
        if(tree[node].assign_lazy!=LLONG_MAX){
            tree[node<<1].val=(mid-l+1)*tree[node].assign_lazy;
            tree[(node<<1)+1].val=(r-mid)*tree[node].assign_lazy;
            tree[node<<1].assign_lazy=tree[node].assign_lazy;
            tree[(node<<1)+1].assign_lazy=tree[node].assign_lazy;
            tree[node<<1].add_lazy=0;
            tree[(node<<1)+1].add_lazy=0;
        }
        if(tree[node].add_lazy!=0){
            tree[node<<1].val+=tree[node].add_lazy*(mid-l+1);
            tree[(node<<1)+1].val+=tree[node].add_lazy*(r-mid);
            tree[node<<1].add_lazy+=tree[node].add_lazy;
            tree[(node<<1)+1].add_lazy+=tree[node].add_lazy;
        }
        tree[node].assign_lazy=LLONG_MAX;
        tree[node].add_lazy=0;
    }
    int query(int node, int l,int r, int st ,int sp){  
        if(st>r || sp<l) return 0;    
        if(st>=l&&sp<=r) return tree[node].val;
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1); 
        pushdown(node,st,mid,sp);
        return query(lft,l,r,st,mid) + query(rght,l,r,mid+1,sp);
    }
    void update_add(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].val+=(sp-st+1)*value;
            tree[node].add_lazy+=value;
            return;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node,st,mid,sp);
            update_add(lft,l,r,st,mid,value);
            update_add(rght,l,r,mid+1,sp,value);
            tree[node].val=tree[lft].val+tree[rght].val;
        }
    }
    void update_assign(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].val=(sp-st+1)*value;
            tree[node].add_lazy=0;
            tree[node].assign_lazy=value;
            return;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node,st,mid,sp);
            update_assign(lft,l,r,st,mid,value);
            update_assign(rght,l,r,mid+1,sp,value);
            tree[node].val=tree[lft].val+tree[rght].val;
        }
    }
};

int32_t main(){
    #ifdef Online_Judge
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
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
            st.update_assign(1,l+1,r,1,n,v);
        }else if(op==2){
            int l,r,v;
            cin>>l>>r>>v;
            st.update_add(1,l+1,r,1,n,v);
        }else if(op==3){
            int l,r;
            cin>>l>>r;
            cout<<st.query(1,l+1,r,1,n)<<endl;
        }        
    }
    return 0;
}