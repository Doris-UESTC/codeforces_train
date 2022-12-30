#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int val;
    int lazy;
    int seg;
    int pref;
    int suf;
    item(){
        val=0;
        lazy=INT_MIN;
        seg=0;
        pref=0;
        suf=0;
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
        if(tree[node].lazy!=INT_MIN){
            tree[node<<1].lazy=tree[node].lazy;
            tree[(node<<1)+1].lazy=tree[node].lazy;
            tree[node<<1].val=(mid-l+1)*tree[node].lazy;
            tree[(node<<1)+1].val=(r-mid)*tree[node].lazy;
            tree[node<<1].seg=(mid-l+1)*tree[node].lazy;
            tree[(node<<1)+1].seg=(r-mid)*tree[node].lazy;
            tree[node<<1].pref=(mid-l+1)*tree[node].lazy;
            tree[(node<<1)+1].pref=(r-mid)*tree[node].lazy;
            tree[node<<1].suf=(mid-l+1)*tree[node].lazy;
            tree[(node<<1)+1].suf=(r-mid)*tree[node].lazy;
			tree[node].lazy=INT_MIN;
        }
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].lazy=value;
            tree[node].val=(sp-st+1)*value;
            tree[node].pref=value>0?(sp-st+1)*value:0;
            tree[node].suf=value>0?(sp-st+1)*value:0;
            tree[node].seg=value>0?(sp-st+1)*value:0;
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
            tree[node].pref=max(tree[lft].pref,tree[lft].val+tree[rght].pref);
            tree[node].suf=max(tree[rght].suf,tree[rght].val+tree[lft].suf);
            tree[node].seg=max(max(tree[lft].seg,tree[rght].seg),tree[lft].suf+tree[rght].pref);
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
        int l,r,v;
        cin>>l>>r>>v;
        st.update(1,l+1,r,1,n,v);
        item ans=st.tree[1];
        cout<<max(max(ans.seg,ans.suf),ans.pref)<<endl;
    }
    return 0;
}