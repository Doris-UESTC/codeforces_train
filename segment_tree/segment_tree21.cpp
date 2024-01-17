#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> element=make_pair(0,0);
class Segment_tree{
    public:
    vector<pair<int,int>> tree;
    Segment_tree(){}
    Segment_tree(int n){
        tree.assign(4*n,element);
    }
    int query(int node, int l,int r, int st ,int sp){  
        if(st>r || sp<l) return 1e18 + 90;    
        if(st>=l&&sp<=r) return tree[node].first;
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1);
        // if(index<=mid){
        //      res=query(lft,index,st,mid);
        // }
        // else{
        //     res=query(rght,index,mid+1,sp);
        // }
        return min(query(lft,l,r,st,mid),query(rght,l,r,mid+1,sp))+tree[node].second;
    }
    int operation(pair<int,int> l ,pair<int,int> r){
        return min(l.first,r.first);
    }
    void update(int node, int l,int r, int st , int sp,int value){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node].first+=value;
            tree[node].second+=value;
            return;
        }else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;
            update(lft,l,r,st,mid,value);
            update(rght,l,r,mid+1,sp,value);
            tree[node].first=operation(tree[lft],tree[rght])+tree[node].second;
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