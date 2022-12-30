#include<bits/stdc++.h>
using namespace std;
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
    void update(int node, int index, int st , int sp, int value){
        if(st > index || sp < index) return ;
        if(st == sp){
            tree[node] = value;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            update(lft,index,st,mid);
            update(rght,index,mid+1,sp);

            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    int operation(int l , int r){
        return l + r ;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    Segment_tree st(2*n);
    vector<int> pos(2*n+1);
    vector<int> ans(n+1);
    for(int i=1;i<=2*n;i++){
        int x;
        cin>>x;
        if(pos[x]==0){
            pos[x]=i;
        }
        else{
            ans[x]=i-pos[x]-1-2*st.query(1,pos[x],i,1,2*n);
            st.update(1,pos[x],1,2*n);
        }
    }
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0 ;
}