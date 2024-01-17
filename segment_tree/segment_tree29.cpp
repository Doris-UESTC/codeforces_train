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
    int find_first(int k,int l,int x,int lx,int rx){
        if(tree[x].val<k)
        return 0;
        if(rx<l)
        return 0;
        if(rx==lx)
        return lx;
        int m=(lx+rx)/2;
        pushdown(x);
        int res=find_first(k,l,2*x,lx,m);
        if(res==0)
        return find_first(k,l,2*x+1,m+1,rx);
        return res;
    }  
    void pushdown(int node){
        if(tree[node].lazy!=0){
            tree[node<<1].lazy+=tree[node].lazy;
            tree[(node<<1)+1].lazy+=tree[node].lazy;
            tree[node<<1].val+=tree[node].lazy;
            tree[(node<<1)+1].val+=tree[node].lazy;
            tree[node].lazy=0;
        }
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].val+=value;
            tree[node].lazy+=value;
            return;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node);
            update(lft,l,r,st,mid,value);
            update(rght,l,r,mid+1,sp,value);
            tree[node].val=max(tree[lft].val,tree[rght].val);
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
            st.update(1,l+1,r,1,n,v);
        }else if(op==2){
            int x,l;
            cin>>x>>l;
            cout<<st.find_first(x,l+1,1,1,n)-1<<endl;
        }        
    }
    return 0;
}