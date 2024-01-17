#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int val;
    int a_lazy;
    int d_lazy;
    item(){
        val=0;
        a_lazy=0;
        d_lazy=0;
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
        if(tree[node].a_lazy!=0 || tree[node].d_lazy!=0){
            tree[node<<1].val+=((mid-l+1)*tree[node].a_lazy+(mid-l)*(mid-l+1)/2*tree[node].d_lazy);
            tree[(node<<1)+1].val+=((r-mid)*tree[node].a_lazy+(r+mid+1-2*l)*(r-mid)/2*tree[node].d_lazy);
            tree[node<<1].a_lazy+=tree[node].a_lazy;
            tree[(node<<1)+1].a_lazy+=tree[node].a_lazy+(mid-l+1)*tree[node].d_lazy;
            tree[node<<1].d_lazy+=tree[node].d_lazy;
            tree[(node<<1)+1].d_lazy+=tree[node].d_lazy;
        }
        tree[node].a_lazy=0;
        tree[node].d_lazy=0;
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
    void update(int node, int l,int r, int st , int sp,int a,int d){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].val+=(sp-st+1)*a+(sp+st-2*l)*(sp-st+1)/2*d;
            tree[node].a_lazy+=(a+(st-l)*d);
            tree[node].d_lazy+=d;
            return;
        }
        else{
            int lft = (node << 1);
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node,st,mid,sp);
            update(lft,l,r,st,mid,a,d);
            update(rght,l,r,mid+1,sp,a,d);
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
            int l,r,a,d;
            cin>>l>>r>>a>>d;
            st.update(1,l,r,1,n,a,d);
        }else if(op==2){
            int t;
            cin>>t;
            cout<<st.query(1,t,t,1,n)<<endl;;
        }
    }
    return 0;
}