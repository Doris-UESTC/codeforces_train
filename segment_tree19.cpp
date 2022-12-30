#include<bits/stdc++.h>
using namespace std;
#define int long long
class Segment_tree{
    public:
    vector<int> tree;
    Segment_tree(){}
    Segment_tree(int n){
        tree.assign(4*n,0);
    }

    int query(int node, int index, int st ,int sp){  
        if(st>index || sp<index) return 0;    
        if(st>=index&&sp<=index) return tree[node];
        int lft = (node << 1) ;
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1) ;
        int res=0;
        if(index<=mid)
        res=query(lft,index,st,mid);
        else
        res=query(rght,index,mid+1,sp);
        return max(res,tree[node]);
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node]=max(value,tree[node]);
            return;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;
            update(lft,l,r,st,mid,value);
            update(rght,l,r,mid+1,sp,value);
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
            int a;
            cin>>a;
            cout<<st.query(1,a+1,1,n)<<endl;
        }
    }
    return 0 ;
}