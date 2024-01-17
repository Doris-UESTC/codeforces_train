#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Segment_tree{
    vector<int> tree;
    void init(int n){
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
            tree[node] = x[st];
            return;
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
    #ifdef Online_Judge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int n,m;
    Segment_tree st[41];
    vector<int> init_array;
    cin>>n>>m;
    init_array.assign(n+1, 0);
    for(int i=0;i<=40;i++){
        st[i].init(n+1);
        st[i].build(1,1,n,init_array);
    }
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        init_array[i]=x;
        st[x].update(1,i,1,n,1);
    }
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            int ans=0;
            for(int j=1;j<=40;j++){
                if(st[j].query(1,l,r,1,n)>0){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }else if(op==2){
            int x,y;
            cin>>x>>y;
            st[init_array[x]].update(1,x,1,n,0);
            init_array[x]=y;
            st[y].update(1,x,1,n,1);
        }
    }
    return 0 ;
}