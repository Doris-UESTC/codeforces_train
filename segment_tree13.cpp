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
    void build(int node, int st , int sp ,vector<int> &x){
        if(st == sp){
            tree[node] = x[st] ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            build(lft,st,mid,x) ;
            build(rght,mid+1,sp,x) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    void update(int node, int index, int st , int sp,int value){
        if(st > index || sp < index) return ;
        if(st == sp){
            tree[node] = value ;
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
    cin>>n;
    vector<int> rec(n+1);
    vector<int> x(n+1);
    for(int i=1;i<=n;i++){
        cin>>rec[i];
        if(i%2==0){
            x[i]=-rec[i];
        }else{
            x[i]=rec[i];
        }
    }
    Segment_tree st(n+1);
    st.build(1,1,n,x);
    cin>>m;
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==0){
            int x,y;
            cin>>x>>y;
            if(x%2==0){
                st.update(1,x,1,n,-y);
            }else{
                st.update(1,x,1,n,y);
            }
        }else if(op==1){
            int x,y;
            cin>>x>>y;
            int ans=st.query(1,x,y,1,n);
            if(x%2==0){
                ans=-ans;
            }
            cout<<ans<<endl;
        }
    }
    return 0 ;
}