#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int lazy;
    int sum;
    int ans;
    item(){
        lazy=0;
        sum=0;
        ans=0;
    }
    void update(int v,int l,int r)
    {
        int len=r-l+1;
        lazy+=v;
        sum+=v*len;
        ans+=len*(len+1)/2*v;
    }
};
item element=item();
vector<int> rec;
class Segment_tree{
    public:
    vector<item> tree;
    Segment_tree(){}
    Segment_tree(int n){
        tree.assign(4*n,element);
    }
    void pushup(int x,int l,int mid,int r)
    {
        tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
        int len=mid-l+1;
        tree[x].ans=tree[x<<1].ans+tree[x<<1|1].ans+tree[x<<1|1].sum*len;
    }
    void build(int x,int l,int r){
        if(l==r){
            tree[x].sum=rec[l];
            tree[x].ans=rec[l];
        }else{
            int mid=(l+r)>>1;
            build(x<<1,l,mid);
            build((x<<1)+1,mid+1,r);
            pushup(x,l,mid,r);
            // tree[x].sum=tree[x<<1].sum+tree[(x<<1)+1].sum;
            // tree[x].ans=tree[x<<1].ans+tree[(x<<1)+1].ans+tree[(x<<1)+1].sum*(mid-l+1);
        }
    }

    void pushdown(int node,int l,int mid,int r){
        // if(tree[node].lazy!=0){
        //     tree[node<<1].sum+=tree[node].lazy*(mid-l+1);
        //     tree[node<<1].lazy+=tree[node].lazy;
        //     tree[(node<<1)+1].sum+=tree[node].lazy*(r-mid);
        //     tree[(node<<1)+1].lazy+=tree[node].lazy;
        //     tree[node<<1].ans+=(r-mid)*(r-mid+1)/2*tree[node].lazy;
        //     tree[(node<<1)+1].ans+=(mid-l+1)*(mid-l+2)/2*tree[node].lazy;
        //     tree[node].lazy=0;
        // }
        int v=tree[node].lazy;
        if(v)
        {
            tree[node<<1].update(v,l,mid);
            tree[node<<1|1].update(v,mid+1,r);
            tree[node].lazy=0;
        }
    }
    int query(int node, int l,int r, int st ,int sp,int h,int q){  
        if(st>r || sp<l) return 0;    
        if(st>=l&&sp<=r) return tree[node].ans+h*tree[node].sum;
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1); 
        pushdown(node,st,mid,sp);
        if(l<=mid) return query(lft,l,r,st,mid,h,q) + query(rght,l,r,mid+1,sp,h+mid-q+1,mid+1);
        else return query(rght,l,r,mid+1,sp,h,q);
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            // tree[node].sum+=value*(sp-st+1);
            // tree[node].lazy+=value;
            // tree[node].ans+=(sp-st+1)*(sp-st+2)/2*value;
            tree[node].update(value,st,sp);
            return;
        }
        else{
            int lft = (node << 1);
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node,st,mid,sp);
            update(lft,l,r,st,mid,value);
            update(rght,l,r,mid+1,sp,value);
            pushup(node,st,mid,sp);
            // tree[node].sum=tree[node<<1].sum+tree[(node<<1)+1].sum;
            // tree[node].ans=tree[node<<1].ans+tree[(node<<1)+1].ans+tree[(node<<1)+1].sum*(mid-st+1);
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
    rec.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>rec[i];
    }
    Segment_tree st(n+1);
    st.build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,d;
            cin>>l>>r>>d;
            st.update(1,l,r,1,n,d);
        }else if(op==2){
            int l,r;
            cin>>l>>r;
            cout<<st.query(1,l,r,1,n,0,1)<<endl;
        }
    }
    return 0;
}