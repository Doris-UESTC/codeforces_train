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
    int find_first(int k,int node,int st,int sp){
        if(st==sp){
			return st;
		}
        int m=(sp+st)/2;
		pushdown(node,st,m,sp);
        int res=tree[2*node].val;
        if(k<=res){
            return find_first(k,2*node,st,m);
        }else{
            return find_first(k-res,2*node+1,m+1,sp);
        }
    }   
    void pushdown(int node,int l,int mid,int r){
        if(tree[node].lazy%2!=0){
            tree[node<<1].lazy+=tree[node].lazy%2;
            tree[(node<<1)+1].lazy+=tree[node].lazy%2;
            tree[node<<1].val=(mid-l+1)-tree[node<<1].val;
            tree[(node<<1)+1].val=(r-mid)-tree[(node<<1)+1].val;
        }   
        tree[node].lazy=0;
    }
    void update(int node, int l,int r, int st , int sp){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].val=(sp-st+1)-tree[node].val;
            tree[node].lazy++;
            return;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1);
            pushdown(node,st,mid,sp);
            update(lft,l,r,st,mid);
            update(rght,l,r,mid+1,sp);
            tree[node].val=(tree[lft].val+tree[rght].val);
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
            int l,r;
            cin>>l>>r;
            st.update(1,l+1,r,1,n);
        }else if(op==2){
            int k;
            cin>>k;
            cout<<st.find_first(k+1,1,1,n)-1<<endl;
        }        
    }
    return 0;
}