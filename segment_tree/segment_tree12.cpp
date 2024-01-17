#include<bits/stdc++.h>
using namespace std;
#define int long long
class Segment_tree{
    public:
    vector<int> tree;
    Segment_tree(int n){
        tree.resize(n*4) ;
    }
    int query(int node, int l,int r, int st ,int sp){
        if(l>sp || r<st) return 0;
        if(l<=st && r>=sp) return tree[node];
        int lft = (node << 1) ;
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1) ;
        return query(rght,l,r,mid+1,sp)+query(lft,l,r,st,mid);
    }
    void build(int node, int st , int sp ){
        if(st == sp){
            tree[node] = 1 ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            build(lft,st,mid) ;
            build(rght,mid+1,sp) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    void update(int node, int index, int st , int sp,int value){
        if(st > index || sp < index) return ;
        if(st == sp){
            tree[node] += value ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            update(lft,index,st,mid,value);
            update(rght,index,mid+1,sp,value);

            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    int operation(int l , int r){
        return l + r ;
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
            st.update(1,l,0,n-1,v);
            st.update(1,r,0,n-1,-v);
        }else if(op==2){
            int index;
            cin>>index;
            int ans=st.query(1,0,index,0,n-1);
            cout<<ans<<endl;
        }
    }
    return 0 ;
}